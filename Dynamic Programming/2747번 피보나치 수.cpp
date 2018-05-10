#include<iostream>
using namespace std;
int D[46];

int go(int n)
{
	if(D[n] != 0 || n < 2) //memoization방법으로 저장된 n번째 값은 다시 계산하지 않고 출력한다. 또한 n이 0이나 1일때 바로 출력한다.
		return D[n];
	return D[n] = go(n-1) + go(n-2);
}

int main(void)
{
	int n;
	
	cin >> n;
	D[1] = 1;
	cout << go(n) << endl;
}
