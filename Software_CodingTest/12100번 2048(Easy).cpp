#include<iostream>
using namespace std;

int Map[20][20];
bool check[20][20];
int N;
int Max;
int dx[4] = {-1, 0, 1, 0}; //↑, ←, ↓, →
int dy[4] = {0, -1, 0, 1};

bool Block_Move(int arr[20][20], int dir)
{
	bool mv_ch = true; //이 함수를 통해 값들이 변한것이 있는지 확인하기 위한 체크 bool
	int i = 0, j = 0;
	int ch = (dx[dir] + dy[dir]) * -1; //방향이 ↑, ← 이라면 0 부터 N-1까지 증가하는 for문, ↓, → 이라면 N-1 부터 0까지 감소하는 for문
	if(dir==2 || dir == 3) //방향이 ↓, → 이라면 실행
	{
		i = N-1;
		j = N-1;
	}
		
	for(; i>=0 && i<N; i+=ch)
	{
		for(; j>=0 && j<N; j+=ch)
		{
			if(arr[i][j] == 0) continue;
			int mx = i; //for문이 돌아가는 i, j는 유지해야 하므로 mx, my에 복사
			int my = j;
			if(mx+dx[dir] < 0 || my+dy[dir] < 0 || mx+dx[dir] > N-1 || my+dy[dir] > N-1) continue; //맵을 벗어나면 continue
						
			while(mx+dx[dir] >= 0 && my+dy[dir] >= 0 && mx+dx[dir] < N && my+dy[dir] < N) //맵안에 있을때만 실행
			{
				if(check[mx+dx[dir]][my+dy[dir]]) break; //체크 된 곳이라면 값을 더해갈 수 없으므로 break;

				if(arr[mx+dx[dir]][my+dy[dir]] == 0) //움직일 곳이 0이라면 이동시켜준다.
				{
					arr[mx+dx[dir]][my+dy[dir]] = arr[mx][my];
					arr[mx][my] = 0;
					mx+=dx[dir]; //이동시킨 후 mx, my를 갱신
					my+=dy[dir];
					mv_ch = false; //이동을 했으므로 mv_ch를 false로 변경
					continue; //0으로 이동한 것이므로 계속 실행한다.
				}
				
				if(arr[mx][my] == arr[mx+dx[dir]][my+dy[dir]]) //이동할 곳과 현재위치의 값이 같다면 실행
				{
					arr[mx][my]=0; //내 위치 0
					mx+=dx[dir]; //위치 갱신
					my+=dy[dir];
					arr[mx][my]*=2; //갱신위치의 값을 2배로
					Max = max(Max, arr[mx][my]); //Max값을 확인
					check[mx][my] = true; //더해진 곳이므로 다시 더할 수 없게 check해준다.
					mv_ch = false; //이동을 했으므로 mv_ch를 false로 변경
					break;
				}
				else //이동할 곳과 현재위치의 값이 다르므로 그만한다.
					break;				
			}
		}
		j = (dir==2 || dir == 3) ? N-1 : 0; //한 i의 열을 전부 움직였으므로 j를 롤백해준다.
	}
	return mv_ch; //변한 것이 있다면 false를 리턴, 변한 것이 없다면 true를 리턴
}

void Easy_Map(int arr[20][20], int dir, int count)
{
	int mv_arr[20][20];

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			mv_arr[i][j] = arr[i][j]; //받아온 배열을 움직일 배열인 mv_arr에 넣어준다.
			check[i][j] = false; //check를 다시 돌려놓는다.
		}

	if(Block_Move(mv_arr, dir)) return; //리턴한 값이 true면 변한것이 없으므로 재귀를 그만한다.
	if(count > 3) return; //3보다 크면 안되므로 재귀를 그만한다.(0, 1, 2, 3, 4) : 5회

	for(int i=0; i<4; i++)
		Easy_Map(mv_arr, i, count+1); //4방향을 돌아준다.
}

int main(void)
{
	cin >> N;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin >> Map[i][j];
			Max = max(Max, Map[i][j]); //현재 맵에서 가장 큰 값을 미리 Max에 넣어준다.
		}

	for(int i=0; i<4; i++)
		Easy_Map(Map, i, 0); //현 위치에서 4방향을 돌아준다.

	cout << Max << endl;
}