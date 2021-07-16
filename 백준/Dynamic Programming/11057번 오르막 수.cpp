#include<iostream>
using namespace std;
int N[1001][10]; //N[n][L] : 길이가 n이고 마지막 숫자가 L로 끝나는 오르막수의 갯수

int main(void)
{
	int n, sum = 0;
	cin >> n;
	N[1][0] = N[1][1] = N[1][2] = N[1][3] = N[1][4] = \
		N[1][5] = N[1][6] = N[1][7] = N[1][8] = N[1][9] = 1; //길이가 1인 오르막 수는 전부 1로 set

	for(int i=2; i<=n; i++) //길이가 2부터 시작해서 n까지
		for(int L=0; L<10; L++) //끝나는 숫자가 0부터 9까지
			for(int j=L; j>=0; j--) //j는 L보다 크면 안되므로 L부터 0까지
			{
				N[i][L] = (N[i][L] + N[i-1][j]) % 10007;
			}
	for(int i=0; i<10; i++)
		sum = (sum + N[n][i]) % 10007;

	cout << sum << endl;
}
