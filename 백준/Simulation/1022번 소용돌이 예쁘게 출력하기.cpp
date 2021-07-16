#include<iostream>
using namespace std;

int find_value(int i, int j)
{
	if(i-j<0)
		if(i+j <0)
			return 4*i*i+i+1-j;
		else
			return 4*j*j-3*j+1-i;
	else
		if(i+j<0)
			return 4*j*j-j+1+i;
		else
			return 4*i*i+3*i+1+j;
}

int main()
{
	int r1, c1, r2, c2;
	int v = 0, len = 0;
	cin >> r1 >> c1 >> r2 >> c2;

	for(int i=r1; i <= r2; i++)
		for(int j=c1; j<=c2; j++)
			if(v < find_value(i, j))
				v = find_value(i, j);

	while(v>0)
	{
		v/=10;
		len++;
	}
	
	for(int i=r1; i <= r2; i++)
	{
		for(int j=c1; j<=c2; j++)
		{
			printf("%*d ", len, find_value(i, j));
		}
		printf("\n");
	}
}
