#include<iostream>
using namespace std;
int N[1001][10]; //N[n][L] : ���̰� n�̰� ������ ���ڰ� L�� ������ ���������� ����

int main(void)
{
	int n, sum = 0;
	cin >> n;
	N[1][0] = N[1][1] = N[1][2] = N[1][3] = N[1][4] = \
		N[1][5] = N[1][6] = N[1][7] = N[1][8] = N[1][9] = 1; //���̰� 1�� ������ ���� ���� 1�� set

	for(int i=2; i<=n; i++) //���̰� 2���� �����ؼ� n����
		for(int L=0; L<10; L++) //������ ���ڰ� 0���� 9����
			for(int j=L; j>=0; j--) //j�� L���� ũ�� �ȵǹǷ� L���� 0����
			{
				N[i][L] = (N[i][L] + N[i-1][j]) % 10007;
			}
	for(int i=0; i<10; i++)
		sum = (sum + N[n][i]) % 10007;

	cout << sum << endl;
}