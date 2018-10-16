#include <iostream>
#include <vector>

using namespace std;

int N, M, size, ch_distance = 5000;
int Map[50][50];

vector<pair<int, int>> chicken;
vector<int> choice;
vector<pair<int, int>> house;


void cal_distance()
{
	int vs_distance = 0;

	int hsize = house.size();
	for(int i=0; i<hsize; i++)
	{
		int x1 = house[i].first;
		int y1 = house[i].second;
		int tmp = 100;

		for(int j=0; j<M; j++)
		{
			int n = choice[j];
			int x2 = chicken[n].first;
			int y2 = chicken[n].second;

			int dis = abs(x1-x2) + abs(y1-y2);
			tmp = tmp > dis ? dis : tmp;
		}

		vs_distance += tmp;
	}

	ch_distance = ch_distance > vs_distance ? vs_distance : ch_distance;
}

void choice_chicken(int x, int cnt)
{
	if(cnt == M)
	{
		cal_distance();
		return;
	}

	for(int i=x+1; i<size; i++)
	{
		choice.push_back(i);
		choice_chicken(i, cnt+1);
		choice.pop_back();
	}
}

int main(void)
{
	cin >> N >> M;

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin >> Map[i][j];
			if(Map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
			if(Map[i][j] == 1)
				house.push_back(make_pair(i, j));
		}

	size = chicken.size();
	for(int i=0; i<size; i++)
	{
		choice.push_back(i);
		choice_chicken(i, 1);
		choice.pop_back();
	}

	cout << ch_distance << endl;
}