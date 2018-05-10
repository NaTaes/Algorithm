#include <iostream>
using namespace std;
int Map[100][100];

int main(void)
{
	int N, n = 0;
	cin >> N;
	int i=0, j=0, k = 1;
	int F = 0;
	int L = N;

	while(n!=N*N)
	{
		for(;j<L && j>=F;j+=k)
			Map[i][j] = ++n;
		j-=k;i+=k;
		if(k==-1) F++;
		if(k==1) L--;
		for(;i<=L && i>=F;i+=k)
			Map[i][j] = ++n;

		i-=k;
		k = k>0?-1:1;
		j+=k;
	}

	k = 0;
	while(n>0)
	{
		n/=10;
		k++;
	}

	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%*d", k+1, Map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
