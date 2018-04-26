#include<iostream>
using namespace std;
int main()
{
	int In, Out, max=0;

	for(int i=0; i<4; i++)
	{
		cin >> Out >> In;
		max = max>max+Out-In?max:max+Out-In;
	}
	cout << max << endl;
}