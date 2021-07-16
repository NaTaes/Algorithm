#include<iostream>
#include<queue>
using namespace std;

char RC[50][50];
int dx[4] = {-1, 1, 0, 0}; //상하좌우
int dy[4] = {0, 0, -1, 1};
int R, C;
int Dx, Dy;

queue<pair<int, int>> gque; //고슴도치 queue
queue<pair<int, int>> wque; //물 queue

int BFS()
{
	int count = 0;
	while(!gque.empty())
	{
		int qsize = gque.size();
		int wsize = wque.size();

		while(qsize--) //고슴도치의 que를 한턴 돌린다.
		{
			int x = gque.front().first;
			int y = gque.front().second;
			gque.pop();

			if(x == Dx && y == Dy) //D의 위치와 같다면 return
				return count;

			if(RC[x][y] != 'S') //자신이 'S'가 아니라면 물에 빠진 상태이므로 continue
				continue;

			for(int i=0; i<4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if(mx < 0 || mx > R-1 || my < 0 || my > C-1) continue;
				if(RC[mx][my] == '.' || RC[mx][my] == 'D') //이동할 위치가 . 이거나 D라면 실행
				{
					RC[mx][my] = 'S';
					gque.push(make_pair(mx, my));
				}
			}
		}
		while(wsize--) //물의 que를 한턴 돌린다.
		{
			int x = wque.front().first;
			int y = wque.front().second;
			wque.pop();

			for(int i=0; i<4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if(mx < 0 || mx > R-1 || my < 0 || my > C-1) continue;
				if(RC[mx][my] == 'D' || RC[mx][my] == 'X' || RC[mx][my] == '*') continue; //이동할 위치가 D, X, * 라면 continue
				RC[mx][my] = '*';
				wque.push(make_pair(mx, my));
			}
		}
		count++; //시간을 증가
	}
	return -1;
}

int main()
{
	cin >> R >> C;

	for(int i=0; i<R; i++)
	{
		scanf("\n");
		for(int j=0; j<C; j++)
		{
			scanf("%c", &RC[i][j]);

			if(RC[i][j] == '*')
				wque.push(make_pair(i, j));
			else if(RC[i][j] == 'S')
				gque.push(make_pair(i, j));
			else if(RC[i][j] == 'D')
			{
				Dx = i;
				Dy = j;
			}
		}
	}
	int result = BFS();

	if(result == -1)
	{
		cout << "KAKTUS" << endl;
		return 0;
	}

	cout << result << endl;
}