#include<iostream>
using namespace std;
int NM[1001][1001];

int main(void)
{
	ios::sync_with_stdio(false); //stdio(�⺻ �����(cin, cout)�� �ð��� �ٿ��ش�.)
	int N, M;
	cin >> N >> M;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
		{
			cin >> NM[i][j];
			NM[i][j] += max(NM[i-1][j], NM[i][j-1]); //���ʰ� ������ ū���� ���� ��ġ�� �����ش�.
		}
			
	cout << NM[N][M] << '\n'; //endl�� �Ⱦ� ������ �ð��� �����ϱ� ���ؼ��̴�.
}