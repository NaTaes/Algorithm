#include<iostream>
using namespace std;
int N[1001];

int go(int n)
{
	if(n<2) // n�� 0�̳� 1�϶�
		return N[n];
	if(N[n] > 0) //memoization �κ�
		return N[n]; 
	N[n] = go(n-1) + (2 * go(n-2)) % 10007; //������ N[n]�� % 10007�� ���־ ������ �־�� �Ѵ�.

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