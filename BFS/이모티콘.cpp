#include<iostream>
#include<queue>
using namespace std;

queue<pair<int, int>> que; //que의 first = 화면 이모티콘 갯수, second = 클립보드 갯수
int S;
int ch[1001][1001]; //화면 이모티콘 갯수와 클립보드 갯수를 확인해 체크

int BFS()
{
	int count=1;
	que.push(make_pair(1, 1));
	while(1)
	{
		int qsize = que.size(); //초당 실행되는 상황을 전부 반복해 확인한다.

		for(int i=0; i<qsize; i++)
		{
			int s = que.front().first;
			int c = que.front().second;
			que.pop();

			if(S==s) //확인하고자 하는 이모티콘과 현재의 이모티콘의 갯수가 같다면
				return count;

			if(ch[s][s] == 0) //(s, c) -> (s, s) 클립보드에 복사(ch[s][s] 확인)
			{
				que.push(make_pair(s, s));
				ch[s][s] = 1; //체크
			}
			if(s+c <= 1000 && ch[s+c][c] == 0) //(s, c) -> (s+c, c) 화면에 복사(ch[s+c][c] 확인)
			{
				que.push(make_pair(s+c, c));
				ch[s+c][c] = 1;
			}
			if(s-1 >=2 && ch[s-1][c] == 0) //(s, c) -> (s-1, c) 화면에서 -1 삭제(ch[s-1][c] 확인)
			{
				que.push(make_pair(s-1, c));
				ch[s-1][c] = 1;
			}
		}
		count++; //한 프레임이 끝나면 초를 증가시킨다.
	}
}

int main(void)
{
	int time;
	cin >> S;

	time = BFS();

	cout << time << endl;
}