#include<iostream>
using namespace std;

int NM[1000][1000];
int dx[2] = {0, -1}; //����, ����
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
				if(i+dx[d] < 0 || i+dx[d] > N-1 || j+dy[d] < 0 || j+dy[d] > M-1) //���� ������ Ȯ��
				{
					candy[d] = 0;
					continue;
				}
				candy[d] = NM[i+dx[d]][j+dy[d]]; //���� ���̸� candy���� ���� or ������ ���� �ִ´�.
			}
			int RC = max(candy[0], candy[1]); ���ʰ� ������ ���� ū���� RC�� �ִ´�.
			NM[i][j] += RC; //i, j ��ġ�� ���� ���Ѵ�.
		}

	cout << NM[N-1][M-1] << endl;
}