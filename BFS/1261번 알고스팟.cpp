#include<iostream>
#include<queue>
using namespace std;

int NM[101][101]; //�˰��� ��
bool ch[101][101]; //check �迭
int N, M;
int dx[4] = {-1, 1, 0, 0}; //��, ��, ��, ��
int dy[4] = {0, 0, -1, 1};

int BFS()
{
	priority_queue<int, vector<int>, greater<int>> que; 
	//�켱���� ť int������ __________________(18bit)_______(7bit)_______(7bit)
	//                        �迭�� ����ġ             ��           ��
	que.push((1<<7)|1); //���� ��ġ�� (0,1,1)�� que�� push
	ch[1][1] = 1; //(1,1)�� check

	while(!que.empty())
	{
		int now = que.top();
		int x = (now&127<<7)>>7; //�ప�� ���� x�� ����
		int y = now&127; //�ప�� ���� y�� ����
		que.pop();

		if(x==N && y==M) //(x,y) == (N,M)�̸� ���
			return NM[x][y];

		for(int i=0; i<4; i++) //�� �� �� �� �̵�
		{
			int mx = x + dx[i];
			int my = y + dy[i];

			//�迭�� ũ�⸦ �Ѿ�ų�, check�� ���̸� continue
			if(mx < 1 || mx > N || my < 1 || my > M || ch[mx][my]) continue;

			NM[mx][my] = NM[x][y] + NM[mx][my]; //�̵��� ���� ���� ������ġ�� �̵��� ��ġ�� ���� �����ش�.
												//�̿� ���� ���� �����ϰ� ���ذ��� �켱���� ť�� ����߱� �����̴�.
												//���� ���� ��ġ���� �˻��� ������ ������ ������ġ�� ���� ���� ���̴�.
			int next = NM[mx][my]<<14 | mx<<7 | my;
			que.push(next);
			ch[mx][my] = 1; //�ش� ��,���� check
		}
	}
}


int main()
{
	scanf("%d %d", &M, &N);
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &NM[i][j]);

	cout << BFS() << endl;
}