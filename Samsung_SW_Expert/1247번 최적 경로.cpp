#include<iostream>
#include<vector>

using namespace std;

pair<int, int> comp;
pair<int, int> home;
vector<pair<int, int>> vec;
bool ch[101][101];
int T, N, total;

void DFS(int dis, int index, int count)
{
	if(count == N)
	{
		dis += (abs(vec[index].first - home.first) + abs(vec[index].second - home.second));
		total = total > dis ? dis : total;
		return;
	}

	for(int i=0; i<vec.size(); i++)
	{
		if(ch[vec[i].first][vec[i].second]) continue;
		ch[vec[i].first][vec[i].second] = true;

		int plus = (abs(vec[i].first - vec[index].first) + abs(vec[i].second - vec[index].second));
		DFS(dis + plus, i, count+1);

		ch[vec[i].first][vec[i].second] = false;
	}
}

int main(void)
{
	int x, y, distance;

	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N;
		cin >> x >> y;
		comp.first = x;
		comp.second = y;

		cin >> x >> y;
		home.first = x;
		home.second = y;

		total = 100 * 100;

		for(int i=0; i<N; i++)
		{
			cin >> x >> y;
			vec.push_back(make_pair(x, y));
		}

		for(int i=0; i<vec.size(); i++)
		{
			if(ch[vec[i].first][vec[i].second]) continue;
			ch[vec[i].first][vec[i].second] = true;

			distance = (abs(vec[i].first - comp.first) + abs(vec[i].second - comp.second));
			DFS(distance, i, 1);

			ch[vec[i].first][vec[i].second] = false;
		}

		vec.clear();
		printf("#%d %d\n", t+1, total);
	}
	return 0;
}