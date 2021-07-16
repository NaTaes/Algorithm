#include<iostream>
#include<vector>
using namespace std;

bool Map[101][101];
vector<pair<int, int>> vec; //선분의 (x,y)값을 저장하는 vector

int dx[4] = {-1, 0, 1, 0}; //←, ↑, →, ↓방향일때 시계방향 90도
int dy[4] = {0, 1, 0, -1};
int x, y, d, g;

void Dragon(int gen)
{
	int index = vec.size() - 1; //현재 세대의 선분의 크기를 index값에 저장한다.
	int dir;
	for(int i=index; i>0; i--) //선분의 길이만큼만 실행한다.(끝점 부터 실행)
	{
		int ex = vec[i].first - vec[i-1].first; //점 과 점의 방향을 알기 위한 ex, ey
		int ey = vec[i].second - vec[i-1].second;
		
		//방향에 맞는 dir을 대입
		if(ex == 0 && ey == 1) dir = 0;
		else if(ex == 1 && ey == 0) dir = 1;
		else if(ex == 0 && ey == -1) dir = 2;
		else dir = 3;

		//계속해서 선분은 추가 될 것이고, 그 추가된 위치를 기준으로 선을 이동시켜야한다.
		int mx = vec[vec.size() - 1].first;
		int my = vec[vec.size() - 1].second;

		vec.push_back(make_pair(mx+dx[dir], my+dy[dir])); //90도 회전된 (x,y)를 선분vector에 추가한다.
		Map[mx+dx[dir]][my+dy[dir]] = true; //Map에 체크해준다.
	}
	gen++;
	if(gen == g) //원하는 세대를 채웠다면 빠져 나온다.
		return;
	else
		Dragon(gen); //원하는 세대가 아니므로 드래곤 커브를 계속 한다.
}

int main(void)
{
	int N, rec = 0;
	cin>> N;

	while(N--)
	{
		cin >> y >> x >> d >> g;

		vec.push_back(make_pair(x, y)); //시작 점을 선분에 넣어준다.
		Map[x][y] = true; //Map 체크

		//d의 값에 맞춰 다음 점을 선분에 넣어준다.
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
		if(g!=0) //세대가 0이라면 드래곤 커브를 실행할 필요없다.
			Dragon(0);
		vec.clear(); //모든 드래곤 커브가 끝나면 선분vector를 clear해준다.
	}

	//1x1의 사각형을 찾아 rec을 증가시킨다.
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
		{
			if(Map[i][j] == false || Map[i][j+1] == false || Map[i+1][j] == false || Map[i+1][j+1] == false) continue;
			rec++;
		}
	cout << rec << endl;
}