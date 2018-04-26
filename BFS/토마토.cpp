#include<iostream>
#include<queue>
using namespace std;
int T[1000][1000];
queue<pair<int,int>> que;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
	int N, M;
	int count = 0;
	cin >> M >> N;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			cin >> T[i][j];
			if(T[i][j] == 1)
				que.push(make_pair(i,j));
		}

	if(que.size() == N*M)
	{
		cout << 0 << endl;
		return 0;
	}
		

	while(!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		count = count>T[x][y]?count:T[x][y];
		for(int i=0; i<4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if(tx >= N || tx < 0 || ty >= M || ty < 0) continue;
			if(T[tx][ty] == 0)
			{
				que.push(make_pair(tx,ty));
				T[tx][ty] = T[x][y] + 1;
			}
		}
	}

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{	
			if(T[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	cout << count-1 << endl;
}