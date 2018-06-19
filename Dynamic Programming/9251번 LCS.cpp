#include<iostream>
#include<string>
using namespace std;

int LCS[1001][1001];

int main(void)
{
	string A, B;

	cin >> A >> B;

	int AL = A.length();
	int BL = B.length();

	for(int i=1; i<=AL; i++)
		for(int j=1; j<=BL; j++)
		{
			if(A[i-1] == B[j-1]) LCS[i][j] = LCS[i-1][j-1]+1;
			else LCS[i][j] = LCS[i-1][j] > LCS[i][j-1] ? LCS[i-1][j] : LCS[i][j-1];
		}
	cout << LCS[AL][BL] << endl;	
}