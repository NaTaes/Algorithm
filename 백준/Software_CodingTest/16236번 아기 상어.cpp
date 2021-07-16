#include<iostream>
#include<queue>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool ch[20][20];
bool ENN[20][20];
int NN[20][20];
int N, BS = 2;
int fishCount, time, result;

queue<pair<int, int>> que;

int chDel()
{
	int x, y;
	for(int i=N-1; i>=0; i--)
		for(int j=N-1; j>=0; j--)
		{
			if(ENN[i][j]) x = i, y = j;
			ENN[i][j] = false;
			ch[i][j] = false;
		}
	return x << 5 | y;
}

int main(void)
{
	cin >> N;

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin >> NN[i][j];

			if(NN[i][j] == 9)
			{
				que.push(make_pair(i, j));
				NN[i][j] = 0;
			}
		}

	while(!que.empty())
	{
		bool findFish = false;
		int size = que.size();

		for(int i=0; i<size; i++)
		{
			int x = que.front().first;
			int y = que.front().second;

			que.pop();

			for(int n=0; n<4; n++)
			{
				int mx = x + dx[n];
				int my = y + dy[n];

				if(mx < 0 || my < 0 || mx > N-1 || my > N-1) continue;
				if(ch[mx][my]) continue;
				
				if(BS < NN[mx][my]) continue; //ÀÌµ¿ °¡´É

				if(NN[mx][my] && BS > NN[mx][my]) //¸Ô´Â´Ù
				{
					ENN[mx][my] = true;
					findFish = true;
				}

				ch[mx][my] = true;
				que.push(make_pair(mx, my));
			}
		}
		time++;

		if(findFish)
		{
			fishCount++;
			if(BS == fishCount)
			{
				BS++;
				fishCount = 0;
			}

			while(!que.empty()) que.pop();
			int tmp = chDel();

			NN[tmp >> 5][tmp & 31] = 0;
			que.push(make_pair(tmp >> 5, tmp & 31));
			result = time;
		}
	}

	cout << result << endl;
}
