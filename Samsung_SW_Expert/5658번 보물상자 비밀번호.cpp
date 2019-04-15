#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

int N, K;

int pow(int a, int b)
{
	int result = 1;

	for(int i=0; i<b; i++)
		result*=a;

	return result;
}

int main(void)
{
	int T;

	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N >> K;
		deque<int> deq;
		priority_queue<int, vector<int>> que;

		for(int i=0; i<N; i++)
		{
			char c;
			scanf("\n");
			scanf("%1c", &c);
			if(c > '9')
				c = c - 'A' + 10;
			else
				c = c - '0';
			deq.push_back(c);
		}

		for(int i=0; i<N/4; i++) //돌리는 횟수
		{
			int num = 0;
			int n = 0;
			for(int j=N-1; j>=0; j--) //값들을 우선순위 큐에 넣기(돌리는 횟수에 맞춰)
			{
				num += (deq[j] * pow(16, n));

				if(n == N/4 -1)
				{
					que.push(num);
					num = 0;
					n = 0;
					continue;
				}
				n++;
			}

			//돌리자
			int tmp = deq[N-1];
			deq.pop_back();
			deq.push_front(tmp);
		}
		
		int size = que.size();
		int count = 0;
		for(int i=0; i<size; i++) //k번째 큰 수 찾기
		{
			int pre = que.top();
			que.pop();
			count++;

			if(count == K)
			{
				printf("#%d %d\n", t+1, pre);
				break;
			}
			
			int next = que.top();

			if(pre == next) 
			{
				que.pop();
				continue;
			}
		}
	}
}
