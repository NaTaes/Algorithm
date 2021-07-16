#include<iostream>
#include<vector>

using namespace std;

vector<int> vec_x;
vector<int> vec_y;

int NM[500][500];

int main(void)
{
	int N, M, Max=0;
	cin >> N >> M;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> NM[i][j];

	//테트로미노 모양 19개
	vec_x.push_back(0), vec_y.push_back(27);
	vec_x.push_back(27), vec_y.push_back(0);
	vec_x.push_back(26), vec_y.push_back(1);
	vec_x.push_back(22), vec_y.push_back(5);
	vec_x.push_back(84), vec_y.push_back(26);
	vec_x.push_back(80), vec_y.push_back(22);
	vec_x.push_back(6), vec_y.push_back(21);
	vec_x.push_back(1), vec_y.push_back(25);
	vec_x.push_back(64), vec_y.push_back(6);
	vec_x.push_back(84), vec_y.push_back(25);
	vec_x.push_back(5), vec_y.push_back(17);
	vec_x.push_back(25), vec_y.push_back(1);
	vec_x.push_back(25), vec_y.push_back(84);
	vec_x.push_back(22), vec_y.push_back(80);
	vec_x.push_back(5), vec_y.push_back(22);
	vec_x.push_back(6), vec_y.push_back(64);
	vec_x.push_back(21), vec_y.push_back(6);
	vec_x.push_back(26), vec_y.push_back(84);
	vec_x.push_back(1), vec_y.push_back(26);


	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			for(int n=0; n<19; n++)
			{
				int x1 = (vec_x[n] >> 6) + i;
				int x2 = ((vec_x[n] >> 4) & 3) + i;
				int x3 = ((vec_x[n] >> 2) & 3) + i;
				int x4 = (vec_x[n] & 3) + i;

				int y1 = ((vec_y[n] >> 6)) + j;
				int y2 = ((vec_y[n] >> 4) & 3) + j;
				int y3 = ((vec_y[n] >> 2) & 3) + j;
				int y4 = (vec_y[n] & 3) + j;

				if(x1 < 0 || x2 < 0 || x3 < 0 || x4 < 0 || x1 > N-1 || x2 > N-1 || x3 > N-1 || x4 > N-1 ||
					y1 < 0 || y2 < 0 || y3 < 0 || y4 < 0 || y1 > M-1 || y2 > M-1 || y3 > M-1 || y4 > M-1) continue; //테트로미노 모양이 맵의 크기를 넘어가면 continue

				Max = max(NM[x1][y1] + NM[x2][y2] + NM[x3][y3] + NM[x4][y4], Max); //테트로미노 모양의 값과 Max값을 비교해 Max에 대입
			}
		}

	cout << Max << endl;
}