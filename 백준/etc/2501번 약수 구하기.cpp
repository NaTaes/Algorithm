#include<iostream>
using namespace std;

int main()
{
	int N, K, i;
	int count=0;
	cin >> N >> K;
	for(i=1; i <= N; i++)
	{
		if(N%i == 0)
			count++;
        	if(count == K)
	            break;
	}
    	if(count < K)
        	i = 0;
	cout << i << endl;
}
