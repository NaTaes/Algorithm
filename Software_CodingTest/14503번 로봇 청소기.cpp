#include<iostream>
using namespace std;

int NM[50][50];
int N, M;
//0(북)의 왼쪽(서)
//1(동)의 왼쪽(북)
//2(남)의 왼쪽(동)
//3(서)의 왼쪽(남)
//의 해당 값을 index로 사용
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int sum = 0;

void Robot_Move(int dir, int x, int y)
{
	NM[x][y]++;
	if(NM[x][y] == 1) //처음 청소를 했다면 sum++를 실행
		sum++;
	int ndir = (dir+3) % 4; //해당 dir에 대한 뒤를 가리키는 index

	if(NM[x+1][y] != 0 && NM[x-1][y] != 0 && NM[x][y+1] != 0 && NM[x][y-1] != 0) //4방향이 모두 청소 또는 벽
	{
		int bx = x + dx[ndir];
		int by = y + dy[ndir];
		if(NM[bx][by] != -1) //뒤가 벽이 아니라면 실행
			Robot_Move(dir, bx, by);
		else //뒤가 벽이라면 재귀를 멈춘다
			return;
	}
	else //4방향 중 청소할 곳이 있다.
	{
		int lx = x + dx[dir];
		int ly = y + dy[dir];
		if(NM[lx][ly] == 0) //왼쪽이 청소한 적 없는 곳이라면 실행
			Robot_Move(ndir, lx, ly);
		else //왼쪽이 벽이거나 청소한 곳이라면 실행
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
			NM[i][j]*=-1; //벽을 -1로 바꿔준다.
		}
	Robot_Move(d, r, c);
	cout << sum << endl;
}
