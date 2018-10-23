#include <iostream>
#include <vector>

using namespace std;

int N;
int NN[100][100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0 ,0};

int block[4][5] = {
	{2, 3, 1, 1, 1},
	{3, 3, 2, 1, 3},
	{1, 3, 2, 1, 1},
	{2, 3, 3, 1, 3}
};

int Total;
int sx, sy;

vector<vector<pair<int, int>>> hall;

void Ball(int x, int y, int dir, int count)
{
	int mx = x;
	int my = y;
	int mdir = dir;

	while(1)
	{
		mx += dx[mdir];
		my += dy[mdir];

		if(mx < 0 || mx > N-1 || my < 0 || my > N-1)
		{
			mdir = (mdir + block[mdir][4]) % 4;
			count++;
			continue;
		}

		if(mx == sx && my == sy)
		{
			Total = max(Total, count);
			break;
		}

		int num = NN[mx][my];

		if(num == 0) //갈 곳이 0이면
		{
			continue; //할게 없어... 더 가
		}
		else if(num == -1) //갈 곳이 블랙홀이면
		{
			//계산하고 그만 해
			Total = max(Total, count);
			break;
		}
		else if(num < 6) //갈 곳이 벽이라면
		{
			//벽을 만나서 방향을 바꿔주고 더 가
			mdir = (mdir + block[mdir][num-1]) % 4;
			count++;
			continue;
		}
		else //갈 곳이 맨홀이라면
		{
			int hx1 = hall[num - 6][0].first;
			int hy1 = hall[num - 6][0].second;
			int hx2 = hall[num - 6][1].first;
			int hy2 = hall[num - 6][1].second;

			if(hx1 == mx && hy1 == my)
			{
				mx = hx2;
				my = hy2;
			}
			else
			{
				mx = hx1;
				my = hy1;
			}
		}
	}
}

int main(void)
{
	int T;

	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N;
		
		hall.resize(5);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{	
				cin >> NN[i][j];
				if(NN[i][j] > 5)
					hall[NN[i][j] - 6].push_back(make_pair(i, j));
			}

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				sx = i;
				sy = j;

				if(NN[i][j] != 0) continue;

				for(int n=0; n<4; n++) //공의 위치에서 방향은 4방향
				{
					Ball(i, j, n, 0);
				}
			}
		}
		printf("#%d %d\n", t+1, Total);
		Total = 0;
		hall.clear();
	}

	return 0;
}