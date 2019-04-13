#include <iostream>
#include <queue>

#define myOper(x) ((x * x) + ((x-1) * (x-1)))

using namespace std;

int NN[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int T, N, M, home, Shome;
bool breakPoint;

void homeSecurity(int x, int y, int k)
{
	queue<pair<int, int> > que;
	bool ch[20][20];
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			ch[i][j] = false;
	int tmpShome = 0;

	que.push(make_pair(x, y));
	ch[x][y] = true;

	int tmpOper = myOper(k);
	while(k--)
	{
		int size = que.size();
		for(int i=0; i<size; i++)
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			if(NN[x][y] == 1) tmpShome++;
			if(k > 0)
			{
				for(int n=0; n<4; n++)
				{
					int mx = x + dx[n];
					int my = y + dy[n];
					if(mx < 0 || my < 0 || mx > N-1 || my > N-1) continue;
					if(ch[mx][my]) continue;
					ch[mx][my] = true;

					que.push(make_pair(mx, my));
				}
			}
		}
	}

	if(tmpOper <= tmpShome * M)
	{
		Shome = Shome < tmpShome ? tmpShome : Shome;
		if(Shome == home) breakPoint = true;
	}
}

int main()
{
	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N >> M;

		Shome = 0;
		home = 0;
		breakPoint = false;

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				cin >> NN[i][j];
				if(NN[i][j] == 1) home++;
			}

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				for(int k=1; ; k++)
				{
					if(myOper(k) > home * M) break;
					if(((k%2)+(k/2)) > N) break;
					if(breakPoint) break;
					homeSecurity(i, j, k);
				}
			}

		printf("#%d %d\n", t+1, Shome);
	}
}