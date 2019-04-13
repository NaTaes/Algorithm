#include <iostream>

using namespace std;

int T, N, Dcount, Dx, Dy;
int NN[20][20];
bool ch[101];

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
int dir[4];

void Dessert_Route(int x, int y, int index)
{
	if(dir[0] < dir[2]) return;

	if((x + dx[index] == Dx && y + dy[index] == Dy) || (dir[0] == dir[2] && dir[1] == 1))
	{
		int tmpDir = dir[0] + dir[1] + dir[2] + dir[3] + 1;
		Dcount = Dcount < tmpDir ? tmpDir : Dcount;
		return;
	}

	for(int i=0; i<2; i++)
	{
		int mx = x + dx[index + i];
		int my = y + dy[index + i];

		if(mx < 0 || my < 0 || mx > N-1 || my > N-1) continue;

		if(ch[NN[mx][my]]) continue;

		ch[NN[mx][my]] = true;
		dir[index+i]++;

		Dessert_Route(mx, my, index + i);

		ch[NN[mx][my]] = false;
		dir[index+i]--;
	}
}

int main()
{
	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N;

		Dcount = -1;

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				cin >> NN[i][j];

		for(int i=0; i<N-2; i++)
			for(int j=1; j<N-1; j++)
			{
				int mx = i + dx[0];
				int my = j + dy[0];

				if(NN[i][j] == NN[mx][my]) continue;
				Dx = i, Dy = j;
				
				ch[NN[i][j]] = true;
				ch[NN[mx][my]] = true;
				dir[0]++;

				Dessert_Route(mx, my, 0);

				ch[NN[i][j]] = false;
				ch[NN[mx][my]] = false;
				dir[0]--;
			}

			printf("#%d %d\n", t+1, Dcount);

			for(int n=1; n<101; n++)
				ch[n] = false;
	}
}