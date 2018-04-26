#include <iostream>
using namespace std;
int Data[20];
int sum;
int S, N, count;

void go(int idx, int sum)
{
	if(Data[idx]+sum == S)
		count++;
	if(idx == N-1)
		return;
	go(idx+1, sum);
	go(idx+1, sum+Data[idx]);
}
 
int main(void)
{
	cin >> N >> S;

	for(int i=0; i<N; i++)
		scanf("%d", &Data[i]);
	
	go(0, 0);
	cout << count << endl;
	return 0;
}

[![문제출저]](https://www.acmicpc.net/problem/1182)
