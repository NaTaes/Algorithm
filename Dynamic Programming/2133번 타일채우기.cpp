#include<iostream>
using namespace std;

int D[31];

//N�� 4�̻���ʹ� ���ο� 2���� ����� �����ȴ�.
//D[N] = 3*D[N-2] + 2*D[N-4] + 2*D[N-6] + 2*D[N-8] + ... + 2*D[N-N]

int main(void)
{
	int N;
	cin >> N;

	D[0] = 1;

	for(int i=2; i<=N; i+=2)
	{
		D[i] = 3*D[i-2];
		for(int j=i; j>2; j-=2)
			D[i] += 2*D[i-j];
	}		

	cout << D[N] << endl;
}