#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A[10][10];
int backA[10][10];
int N, M, K;

queue<pair<int, int>> que;
//vector<int> tree[10][10];

vector<vector<vector<int>>> tree(10, vector<vector<int>>(10));

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool cmp(const int &a, const int &b)
{
	return a < b;
}

void mySort()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			sort(tree[i][j].begin(), tree[i][j].end(), cmp);
}

void fall()
{
	while(!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for(int n=0; n<8; n++)
		{
			int mx = x + dx[n];
			int my = y + dy[n];

			if(mx < 0 || my < 0 || mx > N-1 || my > N-1) continue;
			tree[mx][my].push_back(1);
		}
	}
}

void spring_summer_winter()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			int dieFood = 0;
			for(int n=0; n<tree[i][j].size(); n++)
			{
				if(tree[i][j][n] > A[i][j])
				{
					dieFood += (tree[i][j][n]/2);
					tree[i][j].erase(tree[i][j].begin() + n, tree[i][j].begin() + n + 1);
					n--;
				}
				else
				{
					A[i][j] -= tree[i][j][n];
					tree[i][j][n]++;
					if(tree[i][j][n] % 5 == 0) que.push(make_pair(i, j));
				}
			}
			A[i][j] += (dieFood + backA[i][j]);
		}
}

int main()
{
	int life = 0;

    cin >> N >> M >> K;

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin >> backA[i][j];
			A[i][j] = 5;
		}

	for(int i=0; i<M; i++)
	{
		int tx, ty, n;
		cin >> tx >> ty >> n;
		tree[tx-1][ty-1].push_back(n);
	}

	for(int k=0; k<K; k++)
	{
		mySort();
		spring_summer_winter();
		fall();
	}

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			life += tree[i][j].size();

	cout << life << endl;
}