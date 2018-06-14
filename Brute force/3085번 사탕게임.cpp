#include<iostream>
using namespace std;

char M[50][50];

void SWAP(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

int main(void)
{
	int N;
	int Mmax = 0;
	cin >> N;

	for(int i=0; i<N; i++)
		scanf("%s", M[i]);

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			if(j+1 < N) //���� ����
			{
				int Mtmp1 = 0;
				int Mtmp2 = 0;
				int Mtmp3 = 0;
				int tmp1 = 0;
				int tmp2 = 0;
				int tmp3 = 0;

				SWAP(M[i][j], M[i][j+1]);
				for(int n=0; n<N-1; n++) //�� 1��° ����, �� 1��° ���� ���� Ž���ϱ� ���� for��
				{

					if(M[i][n] == M[i][n+1]) //���� �ش� ���̰�, �� �࿡�� ��� ���� Ž��
					{
						tmp1+=1;
						Mtmp1 = Mtmp1 < tmp1 ? tmp1 : Mtmp1;
					}
					else //�ٸ� ���ڰ� ��Ÿ���ٸ� tmp1�� 0���� ������༭ �ٽ� ī��Ʈ�� ����.
						tmp1 = 0;

					if(M[n][j] == M[n+1][j]) //���� �ش� ���̰�, �� ������ ��� ���� Ž��
					{
						tmp2+=1;
						Mtmp2 = Mtmp2 < tmp2 ? tmp2 : Mtmp2;
					}
					else //�ٸ� ���ڰ� ��Ÿ���ٸ� tmp2�� 0���� ������༭ �ٽ� ī��Ʈ�� ����.
						tmp2 = 0;

					if(M[n][j+1] == M[n+1][j+1]) //���� �ش� ��+1 �̰�, �� ������ ��� ���� Ž��
					{
						tmp3+=1;
						Mtmp3 = Mtmp3 < tmp3 ? tmp3 : Mtmp3;
					}
					else //�ٸ� ���ڰ� ��Ÿ���ٸ� tmp3�� 0���� ������༭ �ٽ� ī��Ʈ�� ����.
						tmp3 = 0;
				}

				int tmax = max(max(Mtmp1, Mtmp2), Mtmp3) + 1; //���� ū tmp���� tmax�� �ִ´�.
				Mmax = Mmax < tmax ? tmax : Mmax; //Mmax�� ���� �� ū���� Mmax�� �ִ´�.
				SWAP(M[i][j], M[i][j+1]);
			}

			if(i+1 < N) //���� ����
			{
				int Mtmp1 = 0;
				int Mtmp2 = 0;
				int Mtmp3 = 0;
				int tmp1 = 0;
				int tmp2 = 0;
				int tmp3 = 0;

				SWAP(M[i][j], M[i+1][j]);
				for(int n=0; n<N-1; n++)
				{

					if(M[n][j] == M[n+1][j])
					{
						tmp1+=1;
						Mtmp1 = Mtmp1 < tmp1 ? tmp1 : Mtmp1;
					}
					else
						tmp1 = 0;

					if(M[i][n] == M[i][n+1])
					{
						tmp2+=1;
						Mtmp2 = Mtmp2 < tmp2 ? tmp2 : Mtmp2;
					}
					else
						tmp2 = 0;

					if(M[i+1][n] == M[i+1][n+1])
					{
						tmp3+=1;
						Mtmp3 = Mtmp3 < tmp3 ? tmp3 : Mtmp3;
					}
					else
						tmp3 = 0;
				}

				int tmax = max(max(Mtmp1, Mtmp2), Mtmp3) + 1;
				Mmax = Mmax < tmax ? tmax : Mmax;
				SWAP(M[i][j], M[i+1][j]);
			}
		}

		cout << Mmax << endl;
}