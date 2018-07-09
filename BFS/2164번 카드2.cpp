#include<iostream>
#include<queue>
using namespace std;

queue<int> que;

int main(void)
{
	int N;
	cin >> N;

	for(int i=1; i<=N; i++)
		que.push(i);

	if(que.size() == 1)
	{
		cout << que.front() << endl;
		return 0;
	}

	while(1)
	{
		que.pop();
		if(que.size() == 1)
			break;

		int tmp = que.front();
		que.pop();
		que.push(tmp);
	}
	cout << que.front() << endl;
}