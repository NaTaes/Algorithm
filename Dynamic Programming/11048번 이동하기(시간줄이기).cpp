#include<iostream>
using namespace std;
int NM[1001][1001];

int main(void)
{
	ios::sync_with_stdio(false); //stdio(기본 입출력(cin, cout)의 시간을 줄여준다.)
	int N, M;
	cin >> N >> M;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
		{
			cin >> NM[i][j];
			NM[i][j] += max(NM[i-1][j], NM[i][j-1]); //왼쪽과 위쪽중 큰값을 현재 위치에 더해준다.
		}
			
	cout << NM[N][M] << '\n'; //endl을 안쓴 이유는 시간을 단축하기 위해서이다.
}