#include <iostream>
#include <vector>

using namespace std;

int T, N, Core, wireLength = 987654321;
bool breakPoint;
int NN[12][12];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dm[3] = {0, 1, -1};

vector<pair<int, int> > vec;

int Ch_Fill_Del(int cindex, int dindex, int mode)
{
	int x = vec[cindex].first;
	int y = vec[cindex].second;
	int len = 0;

	while(true)
	{
		x += dx[dindex];
		y += dy[dindex];

		if(x < 0 || y < 0 || x > N-1 || y > N-1) return len;
		if(mode == 0 && NN[x][y] == 1) return -1;

		NN[x][y] += dm[mode];
		len++;
	}
}

void Process(int Num, int index, int len, int noCore)
{
	if(Core > vec.size() - noCore) return;

	if(Num == Core)
	{
		breakPoint = true;
		wireLength = len < wireLength ? len : wireLength;
		return;
	}

	for(int i = index+1; i<vec.size(); i++)
	{
		for(int n=0; n<4; n++)
		{
			int tmpL = Ch_Fill_Del(i, n, 0);
			if(tmpL == -1) continue;
			Ch_Fill_Del(i, n, 1);
			Process(Num+1, i, len+tmpL, noCore);
			Ch_Fill_Del(i, n, 2);
		}
		noCore++;
	}
}

int main()
{
	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N;

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				cin >> NN[i][j];
				if(i < 1 || j < 1 || i > N-2 || j > N-2) continue;
				if(NN[i][j] == 1) vec.push_back(make_pair(i, j));
			}

		for(int i=vec.size(); i>0; i--)
		{
			Core = i;
			for(int j=0; j<vec.size(); j++)
			{
				for(int n=0; n<4; n++)
				{
					int tmpL = Ch_Fill_Del(j, n, 0);
					if(tmpL == -1) continue;
					Ch_Fill_Del(j, n, 1);
					Process(1, j, tmpL, j);
					Ch_Fill_Del(j, n, 2);
				}
				if(breakPoint) break;
			}
			if(breakPoint) break;
		}
		if(wireLength == 987654321) wireLength = 0;
		printf("#%d %d\n", t+1, wireLength);

		vec.clear();
		breakPoint = false;
		wireLength = 987654321;
	}
}