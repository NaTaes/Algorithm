#include<iostream>
using namespace std;

char NM[50][50];

int main(void)
{
	int M, N;
	int NMmin = 64; //전부 바꿔야하는 상황 최소값

	cin >> M >> N;

	for(int i=0; i<M; i++)
	{
		scanf("\n");
		for(int j=0; j<N; j++)
			scanf("%1c", &NM[i][j]);
	}

	int LM = M-7; //8칸을 확인할 수 있는 최소 행의 위치
	int LN = N-7; //8칸을 확인할 수 있는 최소 열의 위치

	for(int i=0; i<LM; i++)
		for(int j=0; j<LN; j++)
		{
			int count = 0;
			int x = i;
			int y = j;
			for(int h=0; h<8; h++) //8칸의 체스판 뽑아내기(왼쪽 상단 Black)
				for(int w=0; w<8; w++)
				{
					if(!((h+w)%2)) //행+열==짝수 라면 'B'
					{	
						if(NM[x+h][y+w]!='B') //짝수 위치일때 'B'가 아니라면 count++
							count++;
					}
					else //행+열==홀수 라면 'W'
					{
						if(NM[x+h][y+w]!='W') //홀수 위치일때 'W'가 아니라면 count++
							count++;
					}
				}
			NMmin = NMmin > count ? count : NMmin; //최소값을 비교한다.
			
			count = 0;

			for(int h=0; h<8; h++) //8칸의 체스판 뽑아내기(왼쪽 상단 White)
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