#include <iostream>
using namespace std;
int T[16], P[16];
int n, Max;

void go(int i, int m)
{
	if(i == n+1)
	{
		Max = Max < m ? m : Max;
		return;
	}
	if(i > n+1)
		return;

	go(i+T[i], m+P[i]);
	go(i+1, m);

}

int main(void)
{
	cin >> n;

	for(int i=1; i<=n; i++)
	{
		cin >> T[i] >> P[i];
	}

	go(1, 0);

	cout << Max << endl;
}
