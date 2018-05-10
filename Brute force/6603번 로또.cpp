#include <iostream>
using namespace std;
int S[13];
int V[6];
int k;

void go(int i, int n)
{
	if(i == 6)
	{
		for(int j=0; j<6; j++)
			printf("%d ", V[j]);
		printf("\n");
		return;
	}
	if(n > k-1)
		return;

	V[i] = S[n];
	go(i+1, n+1);
	go(i, n+1);
}

int main(void)
{
	while(1)
	{
		cin >> k;
		if(k == 0)
			break;
		for(int i=0; i<k; i++)
			cin >> S[i];

		go(0, 0);
		printf("\n");
	}
}
