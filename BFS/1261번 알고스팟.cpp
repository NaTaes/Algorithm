#include<iostream>
#include<queue>
using namespace std;

int NM[101][101]; //알고스팟 맵
bool ch[101][101]; //check 배열
int N, M;
int dx[4] = {-1, 1, 0, 0}; //상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};

int BFS()
{
	priority_queue<int, vector<int>, greater<int>> que; 
	//우선순위 큐 int형으로 __________________(18bit)_______(7bit)_______(7bit)
	//                        배열의 가중치             행           열
	que.push((1<<7)|1); //시작 위치인 (0,1,1)을 que에 push
	ch[1][1] = 1; //(1,1)은 check

	while(!que.empty())
	{
		int now = que.top();
		int x = (now&127<<7)>>7; //행값을 변수 x에 저장
		int y = now&127; //행값을 변수 y에 저장
		que.pop();

		if(x==N && y==M) //(x,y) == (N,M)이면 출력
			return NM[x][y];

		for(int i=0; i<4; i++) //상 하 좌 우 이동
		{
			int mx = x + dx[i];
			int my = y + dy[i];

			//배열의 크기를 넘어가거나, check된 곳이면 continue
			if(mx < 1 || mx > N || my < 1 || my > M || ch[mx][my]) continue;

			NM[mx][my] = NM[x][y] + NM[mx][my]; //이동할 곳의 값은 현재위치와 이동할 위치의 값을 더해준다.
							    //이와 같은 일을 가능하게 해준것이 우선순위 큐를 사용했기 때문이다.
							    //가장 작은 위치부터 검색해 나가기 때문에 현재위치가 가장 작은 값이다.
			int next = NM[mx][my]<<14 | mx<<7 | my;
			que.push(next);
			ch[mx][my] = 1; //해당 행,열을 check
		}
	}
}

int main()
{
	cin >> M >> N;
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &NM[i][j]);

	cout << BFS() << endl;
}
