#include<iostream>
#define swap(x,y) do{int t; t=x; x=y; y=t;}while(0)
using namespace std;
int A[50];
int B[50];

int main(void)
{
	int N;
	int temp, sum = 0;
	cin >> N;

	for(int i=0; i<N; i++)
		cin >> A[i];
	for(int i=0; i<N; i++)
		cin >> B[i];
	
	for(int i=0; i<N; i++)
	{
		for(int j=i; j<N; j++)
		{
			if(A[i] > A[j]) swap(A[i], A[j]);
			if(B[i] < B[j]) swap(B[i], B[j]);
		}
		sum += A[i]*B[i];
	}
	cout << sum << endl;
}
