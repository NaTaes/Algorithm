#include<iostream>
using namespace std;
int N[10001][3];
int D[10001];
int main()
{
    int n, i;
    cin >> n;
    D[0] = 0;
    for(i=1; i<=n; i++)
        cin >> D[i];
    
    N[1][1] = N[1][2] = D[1];
    N[2][0] = D[1];
    N[2][1] = D[2];
    N[2][2] = D[1] + D[2];
    for(i=3; i<=n; i++)
    {
        N[i][0] = max(max(N[i-1][2], N[i-1][1]), N[i-1][0]);
        N[i][1] = N[i-1][0] + D[i];
        N[i][2] = N[i-1][1] + D[i];
    }  
    cout << max(max(N[n][0], N[n][1]), N[n][2]) << endl;
}
