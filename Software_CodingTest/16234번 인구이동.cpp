#include <iostream>
#include <queue>

using namespace std;

int A[50][50];
bool ch[50][50];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0}; //�� �� �� ��

int main(void)
{
	int N, L, R, count = 0;
	bool condition = true;

	cin >> N >> L >> R;

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> A[i][j];

	while(condition)
	{
		queue<pair<int, int>> que;
		condition = false;

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(ch[i][j]) continue; //�湮���� �ִٸ� continue	
				vector<pair<int, int>> vec;
				
				vec.push_back(make_pair(i, j));
				que.push(make_pair(i, j)); //que push

				while(!que.empty()) //���� ���� ���� Ž��
				{
					int x = que.front().first;
					int y = que.front().second;
					ch[x][y] = true;

					que.pop();

					for(int n=0; n<4; n++) //4���� Ȯ��
					{
						int mx = x + dx[n];
						int my = y + dy[n];

						if(mx < 0 || my < 0 || mx > N-1 || my > N-1) continue; //���� �Ѿ�� continue

						int df = abs(A[x][y] - A[mx][my]);

						if(df < L || df > R) continue; //���� ���� Ȯ��

						if(ch[mx][my]) continue; //�湮�� �� �ִٸ� �湮���� �ʴ´�
						ch[mx][my] = true;

						que.push(make_pair(mx, my)); //���� �� ��ġ push
						vec.push_back(make_pair(mx, my)); //��ġ ���

						condition = true; //�̵��� �����߱� ������ condition�� true �ݺ� �����ϰ� ��
					}
				}

				if(vec.size() > 1)
				{
					int sum = 0;

					for(int n=0; n<vec.size(); n++)
					{
						int x = vec[n].first;
						int y = vec[n].second;

						sum += A[x][y];
					}

					sum /= vec.size();

					for(int n=0; n<vec.size(); n++)
						A[vec[n].first][vec[n].second] = sum;
				}
			}
		}

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				ch[i][j] = false;

		if(condition)
			count++;
	}

	cout << count << endl;
}