#include<iostream>
using namespace std;
int N[100001];

int main()
{
	int n, _max;

	cin >> n;

	for(int i=1; i<=n; i++)
		cin >> N[i];
	
	_max = N[1];
	for(int i=2; i<=n; i++)
	{
		if(N[i]+N[i-1] > N[i])
			N[i] = N[i] + N[i-1];
		_max = _max>N[i]?_max:N[i];
	}

	cout << _max << endl;
}