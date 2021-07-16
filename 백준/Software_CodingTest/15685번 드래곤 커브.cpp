#include<iostream>
#include<vector>
using namespace std;

bool Map[101][101];
vector<pair<int, int>> vec; //������ (x,y)���� �����ϴ� vector

int dx[4] = {-1, 0, 1, 0}; //��, ��, ��, ������϶� �ð���� 90��
int dy[4] = {0, 1, 0, -1};
int x, y, d, g;

void Dragon(int gen)
{
	int index = vec.size() - 1; //���� ������ ������ ũ�⸦ index���� �����Ѵ�.
	int dir;
	for(int i=index; i>0; i--) //������ ���̸�ŭ�� �����Ѵ�.(���� ���� ����)
	{
		int ex = vec[i].first - vec[i-1].first; //�� �� ���� ������ �˱� ���� ex, ey
		int ey = vec[i].second - vec[i-1].second;
		
		//���⿡ �´� dir�� ����
		if(ex == 0 && ey == 1) dir = 0;
		else if(ex == 1 && ey == 0) dir = 1;
		else if(ex == 0 && ey == -1) dir = 2;
		else dir = 3;

		//����ؼ� ������ �߰� �� ���̰�, �� �߰��� ��ġ�� �������� ���� �̵����Ѿ��Ѵ�.
		int mx = vec[vec.size() - 1].first;
		int my = vec[vec.size() - 1].second;

		vec.push_back(make_pair(mx+dx[dir], my+dy[dir])); //90�� ȸ���� (x,y)�� ����vector�� �߰��Ѵ�.
		Map[mx+dx[dir]][my+dy[dir]] = true; //Map�� üũ���ش�.
	}
	gen++;
	if(gen == g) //���ϴ� ���븦 ä���ٸ� ���� ���´�.
		return;
	else
		Dragon(gen); //���ϴ� ���밡 �ƴϹǷ� �巡�� Ŀ�긦 ��� �Ѵ�.
}

int main(void)
{
	int N, rec = 0;
	cin>> N;

	while(N--)
	{
		cin >> y >> x >> d >> g;

		vec.push_back(make_pair(x, y)); //���� ���� ���п� �־��ش�.
		Map[x][y] = true; //Map üũ

		//d�� ���� ���� ���� ���� ���п� �־��ش�.
		if(d % 2==0)
		{	
			vec.push_back(make_pair(x+dx[d+1], y+dy[d+1]));
			Map[x+dx[d+1]][y+dy[d+1]] = true;
		}
		else
		{	
			vec.push_back(make_pair(x+dx[d-1], y+dy[d-1]));
			Map[x+dx[d-1]][y+dy[d-1]] = true;
		}
		if(g!=0) //���밡 0�̶�� �巡�� Ŀ�긦 ������ �ʿ����.
			Dragon(0);
		vec.clear(); //��� �巡�� Ŀ�갡 ������ ����vector�� clear���ش�.
	}

	//1x1�� �簢���� ã�� rec�� ������Ų��.
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
		{
			if(Map[i][j] == false || Map[i][j+1] == false || Map[i+1][j] == false || Map[i+1][j+1] == false) continue;
			rec++;
		}
	cout << rec << endl;
}