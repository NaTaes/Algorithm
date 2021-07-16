#include<iostream>
#include<queue>
using namespace std;

int N, K;
int X[100001];
int dx[3] = {-1, 1, 0}; //움직이는 경우의 수 3가지
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
			int qx = x + dx[i]; // -1, 1, 해당값 을 더해준다.
			if(qx >= 0 && qx <= 100000 && X[qx] == 0) // 범위안이고 0은 간적이 없던 곳이다.
			{
				X[qx]=X[x]+1; //간적이 없던 곳이면 +1씩 쌓아간다.
				que.push(qx);
			}
		}
	}
}

int main(void)
{
	cin >> N >> K;

	if(N > K) //N이 K보다 크면 -1 이동으로 밖에 갈 수 없으므로 그냥 N-K를 한다.
	{
		cout << N-K << endl;
		return 0;
	}

	BFS(N);
	cout << X[K]-1 << endl;
}
