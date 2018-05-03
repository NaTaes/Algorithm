#include<iostream>
using namespace std;
int N[101];
int Loop(int n)
{
    if(n==5) return 2;
    int count=0;
    for(int i=1; i<=n; i++)
        if(n%i==0)
            count++;
    N[n] = Loop(n-1) + count%2;
    return N[n];
}
int main()
{
    int T, n;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> n;
        cout << Loop(n) << endl;
    }
}


