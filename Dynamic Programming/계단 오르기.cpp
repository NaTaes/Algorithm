#include<iostream>
using namespace std;
int N[301][3];
int D[301];
int main()
{
    int n, i;
    cin >> n;
    N[0][1] = N[0][2] = 0;
    D[0] = 0;

    for(i=1; i<=n; i++)
    {
        cin >> D[i];
    }
    N[1][1] = N[1][2] = D[1];
    for(i=2; i<=n; i++)
    {
        int temp;
        N[i][1] = N[i-2][1] + D[i];
        temp = N[i][1];
        if(temp < N[i-2][2] + D[i])
            N[i][1] = N[i-2][2] + D[i];
        N[i][2] = N[i-1][1] + D[i];
    }
    
    cout << max(N[n][1], N[n][2]) << endl;    
}