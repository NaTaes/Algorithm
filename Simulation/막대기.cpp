#include<iostream>
using namespace std;

int main()
{
	int N[] = {1, 2, 4, 8, 16, 32, 64};
	int X, sum=0, count=0;
	
	cin >> X;

	while(X!=sum)
	{
		for(int i=6; i>=0; i--)
		{
			if(X > sum+N[i])
			{
				sum += N[i];
				count++;
			}
			else if(X==sum+N[i])
			{
				sum += N[i];
				count++;
				break;
			}
		}
	}
	cout << count << endl;
}