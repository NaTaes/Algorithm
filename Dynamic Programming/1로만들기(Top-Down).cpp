#include <iostream>
using namespace std;
int D[1000001];
int Loop(int n)
{
	if(n == 1) return 0;
	if(D[n] > 0) return D[n];
	D[n] = Loop(n-1) + 1;
	if(n%2==0)
	{
		int temp = Loop(n/2) + 1;
		if(D[n] > temp) D[n] = temp;
	}
	if(n%3==0)
	{
		int temp = Loop(n/3) + 1;
		if(D[n] > temp) D[n] = temp;
	}
	return D[n];
}

int main() {
	int N;
	cin >> N;
	cout << Loop(N) << '\n';
	return 0;
}