#include <iostream>
#include <queue>

using namespace std;

struct NN_microbe
{
	int num;
	int max;
	int dir;
};

struct que_microbe
{
	int x;
	int y;
	int num;
	int dir;
};

struct NN_microbe NN[100][100];
bool ch[100][100];

int T, N, K, M;

queue<pair<int, int> > backQue;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N >> M >> K;
		
		int total;
		struct que_microbe tmp;
		queue<struct que_microbe> que;

		for(int i=0; i<K; i++)
		{
			cin >> tmp.x >> tmp.y >> tmp.num >> tmp.dir;
			if(tmp.dir == 2) tmp.dir++;
			else if(tmp.dir == 3) tmp.dir--;
			tmp.dir -= 1;

			que.push(tmp);
		}

		while(M--)
		{
			total = 0;
			int size = que.size();
			for(int i=0; i<size; i++)
			{
				int dir = que.front().dir;
				int num = que.front().num;

				int mx = que.front().x + dx[dir];
				int my = que.front().y + dy[dir];

				que.pop();

				if(mx < 1 || my < 1 || mx > N-2 || my > N-2)
				{
					if(num / 2 != 0)
					{
						tmp.x = mx;
						tmp.y = my;
						tmp.num = num / 2;
						tmp.dir = (dir + 2) % 4;
						total += (num / 2);
						que.push(tmp);
					}
					continue;
				}

				NN[mx][my].num += num;
				if(NN[mx][my].max < num)
				{
					NN[mx][my].max = num;
					NN[mx][my].dir = dir;
				}
				
				if(!ch[mx][my])
				{
					backQue.push(make_pair(mx, my));
					ch[mx][my] = true;
				}
			}

			while(!backQue.empty())
			{
				int x = backQue.front().first;
				int y = backQue.front().second;
				backQue.pop();

				total += NN[x][y].num;
				ch[x][y] = false;

				tmp.x = x;
				tmp.y = y;
				tmp.num = NN[x][y].num;
				tmp.dir = NN[x][y].dir;

				que.push(tmp);

				NN[x][y].num = 0;
				NN[x][y].dir = 0;
				NN[x][y].max = 0;
			}
		}

		printf("#%d %d\n", t+1, total);
	}
}