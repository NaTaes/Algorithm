#include<iostream>
#include<vector>

using namespace std;

int Map[8][8];
bool ch[8][8];
int T, N, K, result;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct MapPoint
{
	int x;
	int y;
};

void Go(int x, int y, bool cut, int len)
{
	if(Map[x][y] < 0) return;

	for(int n=0; n<4; n++)
	{
		int mx = x + dx[n];
		int my = y + dy[n];

		if(mx < 0 || my < 0 || mx > N-1 || my > N-1) continue;
		if(ch[mx][my]) continue;

		if(cut)
		{
			if(Map[x][y] > Map[mx][my])
			{
				ch[mx][my] = true;
				result = result < len + 1 ? len + 1 : result;
				Go(mx, my, cut, len+1);
				ch[mx][my] = false;
			}
		}
		else
		{
			ch[mx][my] = true;
			if(Map[x][y] > Map[mx][my])
			{
				result = result < len + 1 ? len + 1 : result;
				Go(mx, my, cut, len+1);
			}
			else
			{
				if(Map[x][y] > Map[mx][my] - K)
				{
					int tmp = Map[mx][my];
					Map[mx][my] = Map[x][y] - 1;
					result = result < len + 1 ? len + 1 : result;
					Go(mx, my, true, len+1);
					Map[mx][my] = tmp;
				}
			}
			ch[mx][my] = false;
		}
	}
}

int main(void)
{
	cin >> T;

	for(int t=0; t<T; t++)
	{
		struct MapPoint MPoint[5];
		int n = 0;

		cin >> N >> K;
		
		result = 1;

		int maxH = 0;

		for(int i=0; i<N; i++)
			for(int j=0; j<N;j++)
			{
				cin >> Map[i][j];
				maxH = maxH < Map[i][j] ? Map[i][j] : maxH;
			}

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				if(maxH == Map[i][j])
				{
					MPoint[n].x = i;
					MPoint[n++].y = j;
				}
			}

		for(int i=0; i<n; i++)
		{
			ch[MPoint[i].x][MPoint[i].y] = true;
			Go(MPoint[i].x, MPoint[i].y, false, 1);
			ch[MPoint[i].x][MPoint[i].y] = false;
		}

		printf("#%d %d\n", t+1, result);
	}

	return 0;
}