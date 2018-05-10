#include<iostream>
#include<queue>
using namespace std;
bool Line[1001][1001];
bool Visit[1001];
int N;

void DFS(int n)
{
	printf("%d ", n);
	Visit[n] = 1;
	for(int i = 1; i <= N; i++)
	{
		if(Line[n][i] && Visit[i] == 0)
			DFS(i);
	}
}

void BFS(int n)
{
	queue<int> que;
	int v;
	que.push(n);
	Visit[n] = 1;
	while(!que.empty())
	{
		v = que.front();
		que.pop();
		printf("%d ", v);
		for(int i=1; i<=N; i++)
		{
			if(Line[v][i] && Visit[i] == 0)
			{
				que.push(i);
				Visit[i] = 1;
			}
		}
	}
}

int main()
{
	int M, V;
	int n1, n2;

	cin >> N >> M >> V;

	for(int i=0; i<M; i++)
	{
		cin >> n1 >> n2;
		Line[n1][n2] = Line[n2][n1] = 1;
	}

	DFS(V);

	for(int i=1; i<=N; i++)
		Visit[i] = 0;
	printf("\n");

	BFS(V);
}
