#include<iostream>
using namespace std;

int value(int n)
{
	int sum = n;
	while(n!=0) //자리수를 분해해 더한다.
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(void)
{
	int N, Divsum;

	cin >> N; //분해합값

	for(int i=0; i<=1000000; i++)
	{
		Divsum = value(i); //생성자 i를 분해합 시킨 값을 Divsum에 대입
		if(Divsum == N) //분해합이 같다면 출력
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl; //생성자가 없다면 0을 출력
}