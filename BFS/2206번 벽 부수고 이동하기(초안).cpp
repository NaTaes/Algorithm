#include<iostream>
#include<queue>
using namespace std;

bool NM[1000][1000];
int ch[1000][1000]; //_______________________________(31bit)_(1bit) 1bit : �� �ν����� üũ
					//31bit : �̵��ð�
int N, M;
int dx[4] = {-1, 1, 0, 0}; //�����¿�
int dy[4] = {0, 0, -1, 1};

int BFS()
{
	queue<pair<int, int>> que;
	que.push(make_pair(0,0));
	ch[0][0] = 1<<1; //(0, 0) �̵��ð� 1

	while(!que.empty())
	{
		int qsize = que.size();
		for(int i=0; i<qsize; i++)
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			if(x == N-1 && y == M-1) //��������� return
				return ch[x][y]>>1;

			for(int n = 0; n<4; n++)
			{
				int mx = x + dx[n];
				int my = y + dy[n];

				if(mx < 0 || mx > N-1 || my < 0 || my > M-1) continue; //���� ���̸� continue

				if(NM[mx][my] == true && (ch[x][y]&1) == 0) //�̵��� ���� ���̰�, ���� �μ��� ���ٸ� ����
				{
					if(ch[mx][my]>>1 == 0) //�̵��� ���� ���� 0�̶�� ���� ���°��̱⶧���� ���� �ִ´�.
					{
						ch[mx][my] = ch[x][y] + 3; //3 = 0011(bit)�̹Ƿ� �̵��ð��� +1, �� üũ +1
						que.push(make_pair(mx,my));
						continue;
					}
				}

				if(NM[mx][my] == false) //�̵��� ���� ���� �ƴ϶�� ����
				{
					if(ch[mx][my]>>1 == 0) //�̵��� ���� ���� 0�̶�� ���� ���°��̱⶧���� ���� �ִ´�.
					{
						ch[mx][my] = ch[x][y] + 2; //2 = 0010(bit)�̹Ƿ� �̵��ð��� +1, �� üũ +0
						que.push(make_pair(mx,my));
						continue;
					}
					//�̵��� ���� ���� 0�� �ƴҶ�
					else if((ch[x][y]>>1)+1 == ch[mx][my]>>1) //���� ��ġ�� ��+1�� �̵��� ���� ���� ���ؼ� ���ٸ� ����
					{
						ch[mx][my] = ch[x][y]+2 > ch[mx][my] ? ch[mx][my] : ch[x][y] + 2; //���� ��ġ�� ���� �̵��� ���� ��ġ�� ���� ���ٸ� �� üũ���� ���� �̵��� ���� ����
					}
					else if((ch[mx][my]&1) && (ch[x][y]&1) == 0 && (ch[x][y] >> 1) > (ch[mx][my]>>1)) 
					{//�̵��� ��ġ�� ���� �ְ�, ���� ��ġ�� ���� �μ��� ����, ���� ��ġ�� ���� �̵��� ���� ������ ũ�ٸ� ����
						//�̵��� ���� �����ִٴ� ���� que�� ������ �������ٴ� ���̴�. �׷��ٸ� �״����� ���� ��ġ�� ���ٴ� ����
						//���� �μ��� ���� ��� ������ �����ߴٴ� ���̹Ƿ� ���Ӱ� ���� �������־�� �Ѵ�.
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