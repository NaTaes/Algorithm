#include<iostream>
using namespace std;

int D[201][201];

//D[n][m] = n개의 갯수를 이용해 m을 만들 수 있는 경우의 수
//D[n][m] = D[n-1][m] + D[n-1][m-1] + D[n-1][m-2] + ... + D[n-1][0]

int main(void)
{
	int N, K;

	cin >> N >> K;

	for(int i=0; i<=N; i++)
		D[1][i] = 1;

	for(int i=2; i<=K; i++)
		for(int n=0; n<=N; n++)
			for(int j=0; j<=n; j++)
				D[i][n] = (D[i][n] + D[i-1][j]) % 1000000000;

	cout << D[K][N] << endl;
}