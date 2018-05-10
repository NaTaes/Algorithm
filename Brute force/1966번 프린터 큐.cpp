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
				que.push(make_pair(1, n)); //1이 내가 뽑을 위치o
			else
				que.push(make_pair(0, n)); //0은 내가 뽑을 위치x
			pque.push(n);
		}

		while(1)
		{
			int q = pque.top(); //중요도가 가장 큰 값을 뽑아낸다.
			if(que.front().second == q) //가장 큰 중요도와 같다면 실행
			{
				if(que.front().first == 1) //가장 큰 중요도이면서 내가 뽑아야할 위치라면
				{
					count++;
					break;
				}
				count++;
				que.pop(); //뽑아낸다.
				pque.pop(); //가장 큰 중요도를 뽑아낸다.
			}
			else //가장 큰 중요도가 아니라면 뒤로 넘긴다
			{
				que.push(make_pair(que.front().first, que.front().second)); //맨 앞 큐를 맨 뒤로
				que.pop(); //맨 앞 큐는 삭제
			}
		}
		cout << count << endl;
		while(!que.empty()) //한 회가 끝나면 큐를 비운다.
			que.pop();
		while(!pque.empty()) //한 회가 끝나면 우선순위 큐를 비운다.
			pque.pop();
	}
}
