#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int NM[50][50];
bool ch[50][50];
int T, N, M, R, C, L;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int> > que;
vector<vector<int> > vec(7);

int main()
{
	cin >> T;

	vec[0].push_back(0), vec[0].push_back(1),vec[0].push_back(2), vec[0].push_back(3);
	vec[1].push_back(0), vec[1].push_back(1);
	vec[2].push_back(2), vec[2].push_back(3);
	vec[3].push_back(0), vec[3].push_back(3);
	vec[4].push_back(1), vec[4].push_back(3);
	vec[5].push_back(1), vec[5].push_back(2);
	vec[6].push_back(0), vec[6].push_back(2);

	for(int t=0; t<T; t++)
	{
		int total = 0;

		cin >> N >> M >> R >> C >> L;

		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				cin >> NM[i][j];

		que.push(make_pair(R, C));
		ch[R][C] = true;

		while(L--)
		{
			int size = que.size();
			total += size;
			for(int i=0; i<size; i++)
			{
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				for(int n=0; n<vec[NM[x][y]-1].size(); n++)
				{
					int mx = x + dx[vec[NM[x][y]-1][n]];
					int my = y + dy[vec[NM[x][y]-1][n]];

					if(mx < 0 || my < 0 || mx > N-1 || my > M-1) continue;
					if(NM[mx][my] == 0) continue;
					if(ch[mx][my]) continue;

					for(int k=0; k<vec[NM[mx][my]-1].size(); k++)
					{
						int kx = dx[vec[NM[x][y]-1][n]] + dx[vec[NM[mx][my]-1][k]];
						int ky = dy[vec[NM[x][y]-1][n]] + dy[vec[NM[mx][my]-1][k]];
						if(kx == 0 && ky == 0)
						{
							ch[mx][my] = true;
							que.push(make_pair(mx, my));
							break;
						}
					}
				}
			}
		}

		printf("#%d %d\n", t+1, total);
		
		while(!que.empty())
			que.pop();

		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				ch[i][j] = false;
	}
}