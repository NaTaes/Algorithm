#include<iostream>
using namespace std;

int main()
{
	unsigned long long A, B, n, sum=0;
	cin >> A >> B;
	
	n=2;
	while(n<=B)
	{
		sum+=((B+n)/(n*2))*n;
		n*=2;
	}
	sum+=(B+1)/2;

	n=2;
	while(n<=A-1)
	{
		sum-=((A-1+n)/(n*2))*n;
		n*=2;
	}
	sum-=A/2;

	cout << sum << endl;
}
