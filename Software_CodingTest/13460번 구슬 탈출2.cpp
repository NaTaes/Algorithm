#include<iostream>
using namespace std;

char NM[10][10];
int check[10][10][10][10]; //�湮 üũ �迭
int dx[4] = {0, 0, 1, -1}; //��, ��, ��, ��
int dy[4] = {1, -1, 0, 0};

int Ox, Oy;
int Rol = 11;

int Move_index(int index, int dir, bool RB)
{
	int rx = index & 15;
	int ry = (index >> 4) & 15;
	int bx = (index >> 8) & 15;
	int by = (index >> 12) & 15;

	if(RB) //�������� ���� ������.
	{
		while(NM[rx+dx[dir]][ry+dy[dir]] != '#') //���� ���� ���� ���� �Ű澲��ȴ�.
		{
			rx+=dx[dir];
			ry+=dy[dir];
			if(rx == Ox && ry == Oy) break; //�����̶�� �������´�.
		}
		while(NM[bx+dx[dir]][by+dy[dir]] != '#' && ((bx+dx[dir] == Ox && by+dy[dir] == Oy) || (bx+dx[dir] != rx || by+dy[dir] != ry))) //���߿� �������� ���� �������� ��ġ, ����, ���� �Ű����Ѵ�.
		{
			bx+=dx[dir];
			by+=dy[dir];
			if(bx == Ox && by == Oy) break;
		}
	}
	else //�Ķ����� ���� ������.
	{
		while(NM[bx+dx[dir]][by+dy[dir]] != '#')
		{
			bx+=dx[dir];
			by+=dy[dir];
			if(bx == Ox && by == Oy) break;
		}
		while(NM[rx+dx[dir]][ry+dy[dir]] != '#' && ((rx+dx[dir] == Ox && ry+dy[dir] == Oy) || (rx+dx[dir] != bx || ry+dy[dir] != by)))
		{
			rx+=dx[dir];
			ry+=dy[dir];
			if(rx == Ox && ry == Oy) break;
		}
	}
	return rx | (ry << 4) | (bx << 8) | (by << 12);
}


void Marble_Move(int index, int dir, int count)
{
	if(count > 11) return; //��ȸ�� 11ȸ �Ѿ�� ������ �����.(���� count�� 1�̹Ƿ� 11ȸ����)

	int rx = index & 15;
	int ry = (index >> 4) & 15;
	int bx = (index >> 8) & 15;
	int by = (index >> 12) & 15;

	check[rx][ry][bx][by] = count; //�ش���ġ�� �湮�� count�� �־��ش�.

	if(bx == Ox && by == Oy) return; //�Ķ����� ���ۿ� �����ٸ� �����.
	if(rx == Ox && ry == Oy) //�������� ���ۿ� �����ٸ� count���� ������� �� �����.
	{
		Rol = min(count - 1, Rol);
		return;
	}

	int output;

	//������ ���⿡ �°� output�� �̾Ƴ���.
	if(dir == 0)
		output = ry < by ? Move_index(index, dir, false) : Move_index(index, dir, true);
	else if(dir == 1)
		output = ry < by ? Move_index(index, dir, true) : Move_index(index, dir, false);
	else if(dir == 2)
		output = rx < bx ? Move_index(index, dir, false) : Move_index(index, dir, true);
	else
		output = rx < bx ? Move_index(index, dir, true) : Move_index(index, dir, false);

	if(index == output) return; //������ ������ ���� ����� ���ٸ� �����.

	rx = output & 15;
	ry = (output >> 4) & 15;
	bx = (output >> 8) & 15;
	by = (output >> 12) & 15;
	
	if(check[rx][ry][bx][by] != 0 && check[rx][ry][bx][by] <= count) return; //������ ��ġ�� �湮üũ�迭�� count���� �۰ų� ���ٸ� �����.
	
	//4������ �������� �����Ѵ�.
	Marble_Move(output, 0, count+1);
	Marble_Move(output, 1, count+1);
	Marble_Move(output, 2, count+1);
	Marble_Move(output, 3, count+1);
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	int input = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			scanf("\n");
			scanf("%1c", &NM[i][j]);
			if(NM[i][j] == 'R')
				input |= i, input |= (j << 4);
			if(NM[i][j] == 'B')
				input |= (i << 8), input |= (j << 12);
			if(NM[i][j] == 'O')
				Ox = i, Oy = j;
		}

	Marble_Move(input, 0, 1);
	Marble_Move(input, 1, 1);
	Marble_Move(input, 2, 1);
	Marble_Move(input, 3, 1);

	if(Rol == 11)
		cout << -1 << endl;
	else
		cout << Rol << endl;
}