#include<iostream>
using namespace std;
int N[10];

int main()
{
	int A, B, C;
	int Num;
	
	cin >> A >> B >> C;
	
	Num = A * B * C;

	while(Num>0)
	{
		N[Num%10]++;
		Num/=10;
	}
	for(int i=0; i<10; i++)
		cout << N[i] << endl;
	return 0;
}
