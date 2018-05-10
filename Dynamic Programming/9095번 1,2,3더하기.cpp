#include<iostream>
using namespace std;

int M[11];
int Loop(int n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    if(M[n]>0) return M[n];
    
    M[n] = Loop(n-3) + Loop(n-2) + Loop(n-1);
    
    return M[n];
}

int main()
{
    int T, n[11];
    cin >> T;
    for(int i=0; i<T; i++) cin >> n[i];
    
    for(int i=0; i<T; i++)
    {
        cout << Loop(n[i]) << '\n';
    }
    
    return 0;
}
