#include<iostream>
using namespace std;
int D[46];

int go(int n)
{
	if(D[n] != 0 || n < 2) //memoization������� ����� n��° ���� �ٽ� ������� �ʰ� ����Ѵ�. ���� n�� 0�̳� 1�϶� �ٷ� ����Ѵ�.
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