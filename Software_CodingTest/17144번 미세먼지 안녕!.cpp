#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int RC[50][50];
int myPlus[50][50];

int R, C, T, total;

int dx[2][4] = {{-1, 0, 1, 0}, {1, 0, -1, 0}};
int dy[2][4] = {{0, 1, 0, -1}, {0, 1, 0, -1}};

queue<pair<int, int>> que;
vector<pair<int, int>> vec;

void searchDust()
{
	total = 0;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
		{
			RC[i][j] += myPlus[i][j];
			myPlus[i][j] = 0;
			if(RC[i][j] > 0) total += RC[i][j];
			if(RC[i][j] / 5 > 0) que.push(make_pair(i, j));
		}
}

void airClean()
{
	for(int i=0; i<2; i++)
	{
		int dir = 0;
		int x = vec[i].first + dx[i][dir];
		int y = vec[i].second + dy[i][dir];

		int mx = x + dx[i][dir];
		int my = y + dy[i][dir];

		while(mx != vec[i].first || my != vec[i].second)
		{
			RC[x][y] = RC[mx][my];
			myPlus[x][y] = myPlus[mx][my];
			x = mx;
			y = my;

			if(mx + dx[i][dir] < 0 || my + dy[i][dir] < 0 || mx + dx[i][dir] > R-1 || my + dy[i][dir] > C-1) dir++;

			if(x == vec[i].first) dir = 3;

			mx += dx[i][dir];
			my += dy[i][dir];
		}
		RC[x][y] = 0;
		myPlus[x][y] = 0;
	}
}

void spreadDust()
{
	while(!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		int spread = RC[x][y] / 5;
		for(int n=0; n<4; n++)
		{
			int mx = x + dx[0][n];
			int my = y + dy[0][n];

			if(mx < 0 || my < 0 || mx > R-1 || my > C-1) continue;
			if(RC[mx][my] == -1) continue;

			myPlus[mx][my] += spread;
			RC[x][y] -= spread;
		}
	}
}

int main()
{
	cin >> R >> C >> T;

	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
		{
			cin >> RC[i][j];
			if(RC[i][j] / 5 > 0) que.push(make_pair(i, j));
			if(RC[i][j] == -1) vec.push_back(make_pair(i, j)); 
		}

		for(int t=0; t<T; t++)
		{
			spreadDust();
			airClean();
			searchDust();
		}

		cout << total << endl;
}