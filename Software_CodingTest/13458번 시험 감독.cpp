#include<iostream>
using namespace std;

int Cdd[1000000];

int main(void)
{
	int N, B, C;
	long long min = 0;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &Cdd[i]);

	scanf("%d %d", &B, &C);

	for(int i=0; i<N; i++)
	{
		int tmp = Cdd[i] - B; //�Ѱ������� ���� ���ش�.
		min += 1; //�ο� �߰�
		if(tmp <= 0) continue; //�Ѱ����������� �ο��� ������ ���ִٸ� continue�Ѵ�.

		if(tmp%C) //���� �ο����� ���� �������� �ִٸ� ���� ���� +1�� ���ش�.
			min += tmp/C + 1;
		else //�������� ���ٸ� �� ��������ŭ�̹Ƿ� �������� �����ش�.
			min += tmp/C;
	}

	printf("%lld\n", min);
}