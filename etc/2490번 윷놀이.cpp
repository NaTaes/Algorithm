#include<iostream>
using namespace std;
int A[4];

int main()
{
	for(int i=0; i<3; i++)
	{
		cin >> A[0] >> A[1] >> A[2] >> A[3];
		if(A[0]+A[1]+A[2]+A[3] == 3)
			cout << 'A' << endl;
		else if(A[0]+A[1]+A[2]+A[3] == 2)
			cout << 'B' << endl;
		else if(A[0]+A[1]+A[2]+A[3] == 1)
			cout << 'C' << endl;
		else if(A[0]+A[1]+A[2]+A[3] == 0)
			cout << 'D' << endl;
		else
			cout << 'E' << endl;
	}
	return 0;
}
