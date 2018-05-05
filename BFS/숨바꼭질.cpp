#include<iostream>
#include<queue>
using namespace std;

int N, K;
int X[100001];
int dx[3] = {-1, 1, 0}; //�����̴� ����� �� 3����
queue<int> que;

int BFS(int n)
{
	que.push(n);
	X[n] = 1;

	while(!que.empty())
	{
		int x = que.front();
		que.pop();
		if(x == K)
			return X[K];
		dx[2] = x;
		for(int i=0; i<3; i++)
		{
			int qx = x + dx[i]; // -1, 1, �ش簪 �� �����ش�.
			if(qx >= 0 && qx <= 100000 && X[qx] == 0) // �������̰� 0�� ������ ���� ���̴�.
			{
				X[qx]=X[x]+1; //������ ���� ���̸� +1�� �׾ư���.
				que.push(qx);
			}
		}
	}
}

int main(void)
{
	cin >> N >> K;

	if(N > K) //N�� K���� ũ�� -1 �̵����� �ۿ� �� �� �����Ƿ� �׳� N-K�� �Ѵ�.
	{
		cout << N-K << endl;
		return 0;
	}

	BFS(N);
	cout << X[K]-1 << endl;
}