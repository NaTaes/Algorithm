#include<iostream>
using namespace std;

int NM[50][50];
int N, M;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int sum = 0;

void Robot_Move(int dir, int x, int y)
{
	NM[x][y]++;
	if(NM[x][y] == 1) //ó�� û�Ҹ� �ߴٸ� sum++�� ����
		sum++;
	int ndir = (dir+3) % 4;

	if(NM[x+1][y] != 0 && NM[x-1][y] != 0 && NM[x][y+1] != 0 && NM[x][y-1] != 0) //4������ ��� û�� �Ǵ� ��
	{
		int bx = x + dx[ndir];
		int by = y + dy[ndir];
		if(NM[bx][by] != -1) //�ڰ� ���� �ƴ϶�� ����
			Robot_Move(dir, bx, by);
		else //�ڰ� ���̶�� ��͸� �����
			return;
	}
	else
	{
		int lx = x + dx[dir];
		int ly = y + dy[dir];

		if(NM[lx][ly] == 0) //������ û���� �� ���� ���̶�� ����
			Robot_Move(ndir, lx, ly);
		else //������ ���̰ų� û���� ���̶�� ����
			Robot_Move(ndir, x, y);
	}
}

int main(void)
{
	int r, c, d;
	cin >> N >> M;
	cin >> r >> c >> d;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			cin >> NM[i][j];
			NM[i][j]*=-1; //���� -1�� �ٲ��ش�.
		}
	Robot_Move(d, r, c);
	cout << sum << endl;
}