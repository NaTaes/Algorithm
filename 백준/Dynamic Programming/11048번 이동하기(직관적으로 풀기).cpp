#include<iostream>
using namespace std;

int NM[1000][1000];
int dx[2] = {0, -1}; //왼쪽, 위쪽
int dy[2] = {-1, 0}; 

int main(void)
{
	int N, M;
	int candy[2];
	cin >> N >> M;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> NM[i][j];

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			for(int d=0; d<2; d++)
			{
				if(i+dx[d] < 0 || i+dx[d] > N-1 || j+dy[d] < 0 || j+dy[d] > M-1) //범위 밖인지 확인
				{
					candy[d] = 0;
					continue;
				}
				candy[d] = NM[i+dx[d]][j+dy[d]]; //범위 안이면 candy값에 위쪽 or 왼쪽의 값을 넣는다.
			}
			int RC = max(candy[0], candy[1]); 왼쪽과 위쪽의 값중 큰값을 RC에 넣는다.
			NM[i][j] += RC; //i, j 위치에 값을 더한다.
		}

	cout << NM[N-1][M-1] << endl;
}