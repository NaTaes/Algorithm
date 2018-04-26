#include <iostream>
using namespace std;
int D[1000001];
int main() {
	int N;
	cin >> N;
	D[1] = 0;
    
	for(int i = 2; i <= N; i++)
	{
		D[i] = D[i-1] + 1;
		if(i % 2 == 0 && D[i] > D[i/2] + 1) D[i] = D[i/2] +1;
		if(i % 3 == 0 && D[i] > D[i/3] + 1) D[i] = D[i/3] +1;
	}
	cout << D[N] << '\n';
	return 0;
}