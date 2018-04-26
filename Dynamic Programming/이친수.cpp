#include<iostream>
using namespace std;
long long N[91][2];
int main()
{
    int n;
    cin >> n;
    N[1][0] = 0;
    N[1][1] = 1;
    for(int i=2; i<=n; i++)
    {
        N[i][0] = N[i-1][0] + N[i-1][1];
		N[i][1] = N[i-1][0];
    }
    cout << N[n][0] + N[n][1] << endl;
}
