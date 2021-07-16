#include<iostream>
#include<deque>
using namespace std;
deque<int> dq;
deque<int> va;
int main(void)
{
	int N, M, K, s, count=0;
	cin >> N >> M;
	int j;

	for(int i=1; i<=N; i++)
		dq.push_back(i);

	for(int i=0; i<M; i++)
	{
		cin >> K;
		va.push_back(K);
	}

	while(!va.empty())
	{
		K = va.front();
		va.pop_front();
		if(dq.front() == K)
			dq.pop_front();
		else
		{
			s = dq.size();
			for(j=0; j<s; j++)
				if(dq.at(j) == K)
					break;

			if(j > s-j-1)
			{
				while(s-j-1>0)
				{
					dq.push_front(dq.back());
					dq.pop_back();
					j++;
					count++;
				}
				dq.pop_back();
				count++;
			}
			else
			{
				while(j>0)
				{
					dq.push_back(dq.front());
					dq.pop_front();
					j--;
					count++;
				}
				dq.pop_front();
			}
		}
	}

	cout << count << endl;
}
