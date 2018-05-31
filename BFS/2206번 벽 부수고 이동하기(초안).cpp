#include<iostream>
#include<queue>
using namespace std;

bool NM[1000][1000];
int ch[1000][1000]; //_______________________________(31bit)_(1bit) 1bit : 벽 부쉈는지 체크
					//31bit : 이동시간
int N, M;
int dx[4] = {-1, 1, 0, 0}; //상하좌우
int dy[4] = {0, 0, -1, 1};

int BFS()
{
	queue<pair<int, int>> que;
	que.push(make_pair(0,0));
	ch[0][0] = 1<<1; //(0, 0) 이동시간 1

	while(!que.empty())
	{
		int qsize = que.size();
		for(int i=0; i<qsize; i++)
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			if(x == N-1 && y == M-1) //도착지라면 return
				return ch[x][y]>>1;

			for(int n = 0; n<4; n++)
			{
				int mx = x + dx[n];
				int my = y + dy[n];

				if(mx < 0 || mx > N-1 || my < 0 || my > M-1) continue; //범위 밖이면 continue

				if(NM[mx][my] == true && (ch[x][y]&1) == 0) //이동할 곳이 벽이고, 벽을 부순적 없다면 실행
				{
					if(ch[mx][my]>>1 == 0) //이동할 곳의 값이 0이라면 간적 없는곳이기때문에 값을 넣는다.
					{
						ch[mx][my] = ch[x][y] + 3; //3 = 0011(bit)이므로 이동시간에 +1, 벽 체크 +1
						que.push(make_pair(mx,my));
						continue;
					}
				}

				if(NM[mx][my] == false) //이동할 곳이 벽이 아니라면 실행
				{
					if(ch[mx][my]>>1 == 0) //이동할 곳의 값이 0이라면 간적 없는곳이기때문에 값을 넣는다.
					{
						ch[mx][my] = ch[x][y] + 2; //2 = 0010(bit)이므로 이동시간에 +1, 벽 체크 +0
						que.push(make_pair(mx,my));
						continue;
					}
					//이동할 곳의 값이 0이 아닐때
					else if((ch[x][y]>>1)+1 == ch[mx][my]>>1) //나의 위치의 값+1과 이동할 곳의 값을 비교해서 같다면 실행
					{
						ch[mx][my] = ch[x][y]+2 > ch[mx][my] ? ch[mx][my] : ch[x][y] + 2; //나의 위치의 값과 이동할 곳의 위치의 값이 같다면 벽 체크없는 값을 이동할 곳에 대입
					}
					else if((ch[mx][my]&1) && (ch[x][y]&1) == 0 && (ch[x][y] >> 1) > (ch[mx][my]>>1)) 
					{//이동할 위치에 값이 있고, 나의 위치는 벽을 부순적 없고, 나의 위치의 값이 이동할 곳의 값보다 크다면 실행
						//이동할 곳의 값이있다는 뜻은 que의 한턴이 지나갔다는 뜻이다. 그렇다면 그다음에 나의 위치가 간다는 뜻은
						//벽을 부순적 없는 길로 느리게 도착했다는 뜻이므로 새롭게 값을 셋팅해주어야 한다.
						ch[mx][my] = ch[x][y] + 2;
						que.push(make_pair(mx,my));
					}
				}
			}
		}
	}
	return -1;
}


int main()
{
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &NM[i][j]);

	cout << BFS() << endl;
}