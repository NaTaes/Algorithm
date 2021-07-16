#include<iostream>
using namespace std;

char N[51];

int main(void)
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int count=0;
		int i=0;
		scanf("%s", N);
		while(N[i]!='\0')
		{
			N[i++]=='(' ? count++ : count--;
			if(count < 0) break;
		}
		printf("%s\n", count == 0 ? "YES" : "NO");
	}
}