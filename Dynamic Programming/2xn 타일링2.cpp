#include<iostream>
using namespace std;
int N[1001];

int go(int n)
{
	if(n<2) // n이 0이나 1일때
		return N[n];
	if(N[n] > 0) //memoization 부분
		return N[n]; 
	N[n] = go(n-1) + (2 * go(n-2)) % 10007; //각각의 N[n]에 % 10007을 해주어서 저장해 주어야 한다.

	return N[n];
}

int main(void)
{
	int n;
	cin >> n;
	N[0] = 1;
	N[1] = 1;

	cout << go(n) << endl;
}