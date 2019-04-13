#include <iostream>

using namespace std;

int NN[10][10];
bool ch[10];

int T, N, M, C;
int maxHoney;
int honey;

void honeyTake(int x, int y, int mMax, int limit, int value)
{
	maxHoney = maxHoney < value ? value : maxHoney;

	for(int i = y+1; i < mMax; i++)
	{
		if(ch[i]) continue;
		if(limit + NN[x][i] > C) continue;
		ch[i] = true;
		honeyTake(x, i, mMax, limit + NN[x][i], value + (NN[x][i] * NN[x][i]));
		ch[i] = false;
	}
}

void honeyComb(int x1, int y1, int x2, int y2)
{
	if(x2 != -1 && y2 != -1)
	{
		int tmp;
		for(int i=0; i<M; i++)
		{
			if(NN[x1][y1+i] > C) continue;
			honeyTake(x1, y1+i, y1+M, NN[x1][y1+i], NN[x1][y1+i]*NN[x1][y1+i]);
		}
		tmp = maxHoney;
		maxHoney = 0;
		for(int i=0; i<M; i++)
		{
			if(NN[x2][y2+i] > C) continue;
			honeyTake(x2, y2+i, y2+M, NN[x2][y2+i], NN[x2][y2+i]*NN[x2][y2+i]);
		}
		tmp += maxHoney;
		maxHoney = 0;

		honey = honey < tmp ? tmp : honey;

		return;
	}

	for(int i=x1; i<N; i++)
	{
		int j = x1 == i ? y1 + M : 0;
		for(; j<N; j++)
		{
			if(j+M > N) continue;
			honeyComb(x1, y1, i, j);
		}
	}
}

int main()
{
	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N >> M >> C;

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				cin >> NN[i][j];

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				if(i == 1 && j == 1)
					int a = 10;
				if(j+M > N) continue;
				honeyComb(i, j, -1, -1);
			}

			printf("#%d %d\n", t+1, honey);
			honey = 0;
	}
}