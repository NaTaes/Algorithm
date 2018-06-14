#include<iostream>
using namespace std;

//T(44) = 990이므로 최대 990까지의 삼각수를 이용한다.

int Possible(int K)
{
	int a, b, c;
	for(int i=1; i<=44; i++)
	{
		a = (i+1)*i/2;
		if(a>=K) break; //1번째 값이 K값과 같거나 더 크다면 나머지 값을 볼 필요없으므로 break;
		for(int j=1; j<=44; j++)
		{
			b = (j+1)*j/2;
			if(b>=K-a) break; //2번째 값이 K-a값과 같거나 더 크다면 나머지 값을 볼 필요없으므로 break;
			for(int n=1; n<=44; n++)
			{
				c = (n+1)*n/2;
				if(c>K-a-b) break; //3번째 값이 K-a-b값보다 크다면 그 이후의 값은 볼 필요없으므로 break;
				if(a+b+c == K) return 1; //3개의 값을 합한 값이 K와 같다면 1을 리턴한다.
			}
		}
	}
	return 0; //전부 돌은 후 내려왔다면 유레카 이론이 아니므로 0을 리턴한다.
}

int main(void)
{
	int T, K;

	cin >> T;

	while(T--)
	{
		cin >> K;
		cout << Possible(K) << endl;
	}
}