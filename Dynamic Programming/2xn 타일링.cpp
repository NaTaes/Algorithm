#include <iostream>
using namespace std;

int M[1001];
int Loop(int n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    if(M[n]>0) return M[n];
    
    M[n] = Loop(n-1) + Loop(n-2);
    
    return M[n]%10007;
}

int main()
{
    int n;
    cin >> n;
    
    cout << Loop(n) << '\n';
}