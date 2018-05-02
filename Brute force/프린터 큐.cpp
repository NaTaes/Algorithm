#include<iostream>
#include<queue>
using namespace std;
queue <pair<int, int>> que;
priority_queue<int> pque;

int main(void)
{
	int T, N, M, n;
	int count;
	cin >> T;

	while(T--)
	{
		count = 0;
		cin >> N >> M;

		for(int i=0; i<N; i++)
		{
			cin >> n;
			if(i == M)
				que.push(make_pair(1, n));
			else
				que.push(make_pair(0, n));
			pque.push(n);
		}

		while(1)
		{
			int q = pque.top();
			if(que.front().second == q)
			{
				if(que.front().first == 1)
				{
					count++;
					break;
				}
				count++;
				que.pop();
				pque.pop();
			}
			else
			{
				que.push(make_pair(que.front().first, que.front().second));
				que.pop();
			}
		}
		cout << count << endl;
		while(!que.empty())
			que.pop();
		while(!pque.empty())
			pque.pop();
	}
}
