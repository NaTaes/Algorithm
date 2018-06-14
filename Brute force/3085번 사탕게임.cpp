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
			if(j+1 < N) //가로 스왑
			{
				int Mtmp1 = 0;
				int Mtmp2 = 0;
				int Mtmp3 = 0;
				int tmp1 = 0;
				int tmp2 = 0;
				int tmp3 = 0;

				SWAP(M[i][j], M[i][j+1]);
				for(int n=0; n<N-1; n++) //행 1번째 부터, 열 1번째 부터 전부 탐색하기 위한 for문
				{

					if(M[i][n] == M[i][n+1]) //행은 해당 행이고, 그 행에서 모든 열을 탐색
					{
						tmp1+=1;
						Mtmp1 = Mtmp1 < tmp1 ? tmp1 : Mtmp1;
					}
					else //다른 문자가 나타난다면 tmp1을 0으로 만들어줘서 다시 카운트를 센다.
						tmp1 = 0;

					if(M[n][j] == M[n+1][j]) //열을 해당 열이고, 그 열에서 모든 행을 탐색
					{
						tmp2+=1;
						Mtmp2 = Mtmp2 < tmp2 ? tmp2 : Mtmp2;
					}
					else //다른 문자가 나타난다면 tmp2을 0으로 만들어줘서 다시 카운트를 센다.
						tmp2 = 0;

					if(M[n][j+1] == M[n+1][j+1]) //열을 해당 열+1 이고, 그 열에서 모든 행을 탐색
					{
						tmp3+=1;
						Mtmp3 = Mtmp3 < tmp3 ? tmp3 : Mtmp3;
					}
					else //다른 문자가 나타난다면 tmp3을 0으로 만들어줘서 다시 카운트를 센다.
						tmp3 = 0;
				}

				int tmax = max(max(Mtmp1, Mtmp2), Mtmp3) + 1; //가장 큰 tmp값을 tmax에 넣는다.
				Mmax = Mmax < tmax ? tmax : Mmax; //Mmax와 비교해 더 큰값을 Mmax에 넣는다.
				SWAP(M[i][j], M[i][j+1]);
			}

			if(i+1 < N) //세로 스왑
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