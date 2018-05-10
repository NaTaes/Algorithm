#include<iostream>
using namespace std;

int D[10001]; //가능한 동전의 가짓수
int n[101]; //동전의 가치

int main(void)
{
	int N, k;
	cin >> N >> k;

	for(int i=1; i<=N; i++)
		cin >> n[i];

	D[0] = 1; //0이 가능한 가짓 수 1개(아무것도 뽑지 않는다.)

	//N번개의 동전만큼 1번째 for문을 돌려준다.
	//D[j]는 j까지의 가능한 가짓수이다. 첫 for문은 1번째 동전의 가치만을 생각한다.
	//두번째 for문은 2번째 동전의 가치만을 생각해 D[j]에 쌓아준다.
	for(int i=1; i<=N; i++)
	{
		for(int j=n[i]; j<=k; j++)
		{
			D[j] += D[j-n[i]]; //j를 n[i]부터 시작하기 때문에 if(j-n[i] >= 0)를 할 필요가 없다.
		}
	}
	cout << D[k] << endl;
}
