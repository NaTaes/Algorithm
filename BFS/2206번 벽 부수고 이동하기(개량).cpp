#include<iostream>
#include<queue>
using namespace std;

bool Map[1000][1000];
bool visit[1000][1000][2]; //[][][0] : ���� �μ��� ���� ������ �湮 üũ
							//[][][1] : ���� �μ��� �ִ� ������ �湮 üũ
int dx[4] = {-1, 1, 0, 0}; //�����¿�
int dy[4] = {0, 0, -1, 1};
int N, M;

typedef struct quest{
	int c; //��
	int r; //��
	bool ch; //�� �ν����� üũ
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
		while(quesize--) //que�� ���� �����Ѵ�.
		{
			st = que.front();
			int x = st.c;
			int y = st.r;
			bool check = st.ch;
			que.pop();

			if(x == N-1 && y == M-1) //��������� return
				return count;

			for(int i=0; i<4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if(mx < 0 || mx > N-1 || my < 0 || my > M-1) continue; //���� ���̸� continue
				if(Map[mx][my] && check) continue; //�̵��� ���� ���̰�, ���� �μ� ���¶�� continue

				if(visit[mx][my][check] == 0 && Map[mx][my] == 0)
				{//�̵��� ���� 0 �̰�, �湮���� �ʾҴٸ� ����(�̵��� ���� 0�̹Ƿ� ���� �ν����� üũ���� �ʴ´�.)
					st.c = mx;
					st.r = my;
					st.ch = check;
					que.push(st);
					visit[mx][my][check] = 1;
					continue;
				}
				if(visit[mx][my][1] == 0 && Map[mx][my] == 1 && check == 0)
				{//�̵��� ���� 1 �̰�, ���� �μ� ���·� �湮�� ���� ����, ���� �μ��� ���ٸ� ����
					st.c = mx;
					st.r = my;
					st.ch = 1;
					que.push(st);
					visit[mx][my][1] = 1;
				}
			}
		}
		count++; //que�� ������ ������ ������Ų��.
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