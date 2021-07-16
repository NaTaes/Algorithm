#include<iostream>
#include<queue>
using namespace std;

int NM[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> que;

int main(void)
{
	int N, M;
	cin >> N >> M;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			scanf("%1d", &NM[i][j]);
	}

	que.push(make_pair(0, 0));
	NM[0][0] = 2;
	while(!que.empty())
	{
		int qx = que.front().first;
		int qy = que.front().second;
		que.pop();
		for(int i=0; i<4; i++)
		{
			int x = qx + dx[i];
			int y = qy + dy[i];
			if(NM[x][y] == 1 && x >= 0 && x < N && y >= 0 && y < M)
			{
				NM[x][y] = NM[qx][qy] + 1;
				que.push(make_pair(x, y));
			}
		}
	}
	cout << NM[N-1][M-1]-1 << endl;
}
