#include<iostream>
using namespace std;
int main()
{
    int N, R, G, B;
    int M[1001][3];
    cin >> N;
    M[0][0] = M[0][1] = M[0][2] = 0;
    for(int i=1;i<=N;i++)
    {
        cin >> R >> G >> B;
        
        M[i][0] = min(M[i-1][1], M[i-1][2]) + R;
        M[i][1] = min(M[i-1][0], M[i-1][2]) + G;
        M[i][2] = min(M[i-1][0], M[i-1][1]) + B;
    }
    cout << min(min(M[N][0], M[N][1]), M[N][2]) << '\n';
}
