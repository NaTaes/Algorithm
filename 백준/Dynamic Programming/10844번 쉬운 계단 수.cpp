#include<iostream>
using namespace std;
int N[101][10];
int main()
{
	int n, max=0;
	cin >> n;

	N[1][0] = 0;
	N[1][1] = N[1][2] = N[1][3] = N[1][4] = N[1][5] = N[1][6] = N[1][7] = N[1][8] = N[1][9] = 1;
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<=9; j++)
		{
			if(j-1>=0) N[i][j] += N[i-1][j-1];
			if(j+1<=9) N[i][j] += N[i-1][j+1];
			N[i][j] %= 1000000000;
		}
	}
	for(int i=0; i<10; i++)
		max = (max + N[n][i])%1000000000;
	cout << max << endl;
}
