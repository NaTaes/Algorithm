#include<iostream>
using namespace std;
int Map[100][100];
long N[100][100];
int main()
{
    int n;
    cin >> n;
	N[0][0] = 1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> Map[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(Map[i][j]==0)
                continue;
            if(i+Map[i][j]<=n)
                N[i+Map[i][j]][j]+=N[i][j];
            if(j+Map[i][j]<=n)
                N[i][j+Map[i][j]]+=N[i][j];
        }
    cout << N[n-1][n-1] << endl;
}
