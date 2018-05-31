#include<iostream>
#include<queue>
using namespace std;

bool Map[1000][1000];
bool visit[1000][1000][2]; //[][][0] : 벽을 부순적 없는 상태의 방문 체크
							//[][][1] : 벽을 부순적 있는 상태의 방문 체크
int dx[4] = {-1, 1, 0, 0}; //상하좌우
int dy[4] = {0, 0, -1, 1};
int N, M;

typedef struct quest{
	int c; //행
	int r; //열
	bool ch; //벽 부쉈는지 체크
}questruct;

int BFS()
{
	int count = 1;
	queue<questruct> que;
	questruct st;

	st.c = 0;
	st.r = 0;
	st.ch = false;
	que.push(st);
	visit[0][0][0] = 1;

	while(!que.empty())
	{
		int quesize = que.size();
		while(quesize--) //que를 한턴 실행한다.
		{
			st = que.front();
			int x = st.c;
			int y = st.r;
			bool check = st.ch;
			que.pop();

			if(x == N-1 && y == M-1) //도착지라면 return
				return count;

			for(int i=0; i<4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if(mx < 0 || mx > N-1 || my < 0 || my > M-1) continue; //범위 밖이면 continue
				if(Map[mx][my] && check) continue; //이동할 곳이 벽이고, 벽을 부순 상태라면 continue

				if(visit[mx][my][check] == 0 && Map[mx][my] == 0)
				{//이동할 곳이 0 이고, 방문하지 않았다면 실행(이동할 곳이 0이므로 벽을 부쉈는지 체크하지 않는다.)
					st.c = mx;
					st.r = my;
					st.ch = check;
					que.push(st);
					visit[mx][my][check] = 1;
					continue;
				}
				if(visit[mx][my][1] == 0 && Map[mx][my] == 1 && check == 0)
				{//이동할 곳이 1 이고, 벽을 부순 상태로 방문한 적이 없고, 벽을 부순적 없다면 실행
					st.c = mx;
					st.r = my;
					st.ch = 1;
					que.push(st);
					visit[mx][my][1] = 1;
				}
			}
		}
		count++; //que의 한턴이 끝나면 증가시킨다.
	}
	return -1;
}

int main()
{
	cin >> N >> M;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &Map[i][j]);

	cout << BFS() << endl;
}