#include <iostream>
#include <vector>

using namespace std;

int D, W, K;

int DW_film[13][20];
int medicine = -1;
int max_count;

int cal(int M[13][20])
{
	for(int j=0; j<W; j++)
	{
		int cntMx=1;
		int cnt=1;
		for(int i=0; i<D-1; i++)
		{
			if(M[i][j] == M[i+1][j])	
			{	
				cnt++;
				cntMx = max(cntMx, cnt);
				if(cntMx == K)
					break;
			}
			else
				cnt = 1;
		}
		if(cntMx < K)
			return 0;
	}
	return 1;
}

void make_film(int M[13][20], int count, int x)
{
	if(medicine != -1)
		return;

	if(max_count == count) //약품을 넣은 갯수가 같다면 계산
	{
		if(cal(M)) //K가 맞다면
			medicine = count;
		return;
	}

	for(int i=x; i<D; i++)
	{
		int tmp[13][20]; //복제용
		for(int it=0; it<D; it++)
			for(int jt=0; jt<W; jt++)
			{
				if(it==i)
					tmp[it][jt] = 0;
				else
					tmp[it][jt] = M[it][jt];
			}

		make_film(tmp, count+1, i+1); //A

		if(medicine != -1)
			return;

		for(int jt=0; jt<W; jt++)
			tmp[i][jt] = 1;

		make_film(tmp, count+1, i+1); //B

		if(medicine != -1)
			return;
	}
}

int main(void)
{
	int T;

	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> D >> W >> K;

		for(int i=0; i<D; i++)
			for(int j=0; j<W; j++)
				cin >> DW_film[i][j];

		for(int i=0; i<D; i++) //약품을 넣은 갯수(D보단 작아야한다)
		{
			max_count = i;
			make_film(DW_film, 0, 0);
			if(medicine != -1)
				break;
		}

		printf("#%d %d\n", t+1, medicine);
		medicine = -1;		
	}

	return 0;
}