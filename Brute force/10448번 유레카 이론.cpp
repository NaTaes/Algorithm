#include<iostream>
using namespace std;

//T(44) = 990�̹Ƿ� �ִ� 990������ �ﰢ���� �̿��Ѵ�.

int Possible(int K)
{
	int a, b, c;
	for(int i=1; i<=44; i++)
	{
		a = (i+1)*i/2;
		if(a>=K) break; //1��° ���� K���� ���ų� �� ũ�ٸ� ������ ���� �� �ʿ�����Ƿ� break;
		for(int j=1; j<=44; j++)
		{
			b = (j+1)*j/2;
			if(b>=K-a) break; //2��° ���� K-a���� ���ų� �� ũ�ٸ� ������ ���� �� �ʿ�����Ƿ� break;
			for(int n=1; n<=44; n++)
			{
				c = (n+1)*n/2;
				if(c>K-a-b) break; //3��° ���� K-a-b������ ũ�ٸ� �� ������ ���� �� �ʿ�����Ƿ� break;
				if(a+b+c == K) return 1; //3���� ���� ���� ���� K�� ���ٸ� 1�� �����Ѵ�.
			}
		}
	}
	return 0; //���� ���� �� �����Դٸ� ����ī �̷��� �ƴϹǷ� 0�� �����Ѵ�.
}

int main(void)
{
	int T, K;

	cin >> T;

	while(T--)
	{
		cin >> K;
		cout << Possible(K) << endl;
	}
}