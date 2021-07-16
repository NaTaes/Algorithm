#include<iostream>
using namespace std;
int N[10001];
int D[10001];
int main()
{
    int n, i;
    cin >> n;
    D[0] = 0;
    for(i=1; i<=n; i++)
        cin >> D[i];
    N[0] = 0;
    N[1] = D[1];
    N[2] = D[1] + D[2];
    for(i=3; i<=n; i++)
    {
        N[i] = N[i-1];
        if(N[i] < N[i-2] + D[i])
            N[i] = N[i-2] + D[i];
        if(N[i] < N[i-3] + D[i] + D[i-1])
            N[i] = N[i-3] + D[i] + D[i-1];
    }  
    cout << N[n] << endl;
}
