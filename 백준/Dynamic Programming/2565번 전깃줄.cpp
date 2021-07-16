#include<iostream>

using namespace std;
int A[501];
int D[501];

int main()
{
	int T, max=0;
	cin >> T;

	for(int i=0; i<T; i++)
	{
		int n, k;
		cin >> n >> k;
		A[n] = k; //A쪽 번호를 index, B쪽 번호를 배열의 값
	}
	//가장 긴 증가하는 부분 수열로 만든다.
	for(int i=1; i<=500; i++)
	{
		if(A[i]==0) continue; //값이 없다면 continue
		D[i] = 1;
		int temp = 1;
		for(int j=1; j<i; j++) //가장 긴 증가하는 부분수열(11053번) 문제 참조.
		{
			if(A[i] > A[j] && temp < D[i]+D[j])
			{
				temp = D[i] + D[j];
				max = max < temp ? temp : max;
			}
		}
		D[i] = temp;
    }
    cout << T-max << endl; //없앤 줄 수이므로 총 줄수 - 가장 긴 부분수열의 길이
}
