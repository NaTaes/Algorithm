#include<iostream>
using namespace std;

int value(int n)
{
	int sum = n;
	while(n!=0) //�ڸ����� ������ ���Ѵ�.
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(void)
{
	int N, Divsum;

	cin >> N; //�����հ�

	for(int i=0; i<=1000000; i++)
	{
		Divsum = value(i); //������ i�� ������ ��Ų ���� Divsum�� ����
		if(Divsum == N) //�������� ���ٸ� ���
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl; //�����ڰ� ���ٸ� 0�� ���
}