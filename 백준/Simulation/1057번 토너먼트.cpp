#include<iostream>
using namespace std;
int main()
{
	int N, X, Y;
	int count=0;
	
	cin >> N >> X >> Y;

	while(1)
	{	
		count++;
		if(X%2==1)
			X=(X+1)/2;
		else
			X/=2;
		if(Y%2==1)
			Y=(Y+1)/2;
		else
			Y/=2;
		if(X==Y)
			break;
	}
	cout << count << endl;
}	
