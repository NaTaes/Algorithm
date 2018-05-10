#include<iostream>
using namespace std;
int A[1001];
int D[1001];
int main()
{
    int N, i, j, temp, max=1;
    cin >> N;
    for(i=1; i<=N; i++)
        cin >> A[i];
    
    for(i=1; i<=N; i++)
    {
        D[i] = 1;
        temp = 1;
        for(j=1; j<i; j++)
        {
            if(A[i]>A[j] && temp < D[i]+D[j])
                    temp = D[i]+D[j];
			max = temp>max?temp:max;
        }
        D[i] = temp;
    }  
    cout << max << endl;
}
