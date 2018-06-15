#include<iostream>
using namespace std;

char NM[50][50];

int main(void)
{
	int M, N;
	int NMmin = 64; //���� �ٲ���ϴ� ��Ȳ �ּҰ�

	cin >> M >> N;

	for(int i=0; i<M; i++)
	{
		scanf("\n");
		for(int j=0; j<N; j++)
			scanf("%1c", &NM[i][j]);
	}

	int LM = M-7; //8ĭ�� Ȯ���� �� �ִ� �ּ� ���� ��ġ
	int LN = N-7; //8ĭ�� Ȯ���� �� �ִ� �ּ� ���� ��ġ

	for(int i=0; i<LM; i++)
		for(int j=0; j<LN; j++)
		{
			int count = 0;
			int x = i;
			int y = j;
			for(int h=0; h<8; h++) //8ĭ�� ü���� �̾Ƴ���(���� ��� Black)
				for(int w=0; w<8; w++)
				{
					if(!((h+w)%2)) //��+��==¦�� ��� 'B'
					{	
						if(NM[x+h][y+w]!='B') //¦�� ��ġ�϶� 'B'�� �ƴ϶�� count++
							count++;
					}
					else //��+��==Ȧ�� ��� 'W'
					{
						if(NM[x+h][y+w]!='W') //Ȧ�� ��ġ�϶� 'W'�� �ƴ϶�� count++
							count++;
					}
				}
			NMmin = NMmin > count ? count : NMmin; //�ּҰ��� ���Ѵ�.
			
			count = 0;

			for(int h=0; h<8; h++) //8ĭ�� ü���� �̾Ƴ���(���� ��� White)
				for(int w=0; w<8; w++)
				{
					if(!((h+w)%2))
					{	
						if(NM[x+h][y+w]!='W')
							count++;
					}
					else
					{
						if(NM[x+h][y+w]!='B')
							count++;
					}
				}
			NMmin = NMmin > count ? count : NMmin;
		}

	cout << NMmin << endl;
}