#include<iostream>
using namespace std;

char NM[10][10];
int check[10][10][10][10]; //방문 체크 배열
int dx[4] = {0, 0, 1, -1}; //→, ←, ↓, ↑
int dy[4] = {1, -1, 0, 0};

int Ox, Oy;
int Rol = 11;

int Move_index(int index, int dir, bool RB)
{
	int rx = index & 15;
	int ry = (index >> 4) & 15;
	int bx = (index >> 8) & 15;
	int by = (index >> 12) & 15;

	if(RB) //빨간공을 먼저 굴린다.
	{
		while(NM[rx+dx[dir]][ry+dy[dir]] != '#') //먼저 굴린 공은 벽만 신경쓰면된다.
		{
			rx+=dx[dir];
			ry+=dy[dir];
			if(rx == Ox && ry == Oy) break; //구멍이라면 빠져나온다.
		}
		while(NM[bx+dx[dir]][by+dy[dir]] != '#' && ((bx+dx[dir] == Ox && by+dy[dir] == Oy) || (bx+dx[dir] != rx || by+dy[dir] != ry))) //나중에 굴린공은 먼저 굴린공의 위치, 구멍, 벽을 신경써야한다.
		{
			bx+=dx[dir];
			by+=dy[dir];
			if(bx == Ox && by == Oy) break;
		}
	}
	else //파란공을 먼저 굴린다.
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
	if(count > 11) return; //기회가 11회 넘어가면 실행을 멈춘다.(시작 count가 1이므로 11회까지)

	int rx = index & 15;
	int ry = (index >> 4) & 15;
	int bx = (index >> 8) & 15;
	int by = (index >> 12) & 15;

	check[rx][ry][bx][by] = count; //해당위치의 방문에 count를 넣어준다.

	if(bx == Ox && by == Oy) return; //파란공이 구멍에 빠졌다면 멈춘다.
	if(rx == Ox && ry == Oy) //빨간공만 구멍에 빠졌다면 count값을 계산해준 후 멈춘다.
	{
		Rol = min(count - 1, Rol);
		return;
	}

	int output;

	//움직일 방향에 맞게 output을 뽑아낸다.
	if(dir == 0)
		output = ry < by ? Move_index(index, dir, false) : Move_index(index, dir, true);
	else if(dir == 1)
		output = ry < by ? Move_index(index, dir, true) : Move_index(index, dir, false);
	else if(dir == 2)
		output = rx < bx ? Move_index(index, dir, false) : Move_index(index, dir, true);
	else
		output = rx < bx ? Move_index(index, dir, true) : Move_index(index, dir, false);

	if(index == output) return; //움직인 방향이 현재 방향과 같다면 멈춘다.

	rx = output & 15;
	ry = (output >> 4) & 15;
	bx = (output >> 8) & 15;
	by = (output >> 12) & 15;
	
	if(check[rx][ry][bx][by] != 0 && check[rx][ry][bx][by] <= count) return; //움직일 위치의 방문체크배열의 count값이 작거나 같다면 멈춘다.
	
	//4방향의 움직임을 실행한다.
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