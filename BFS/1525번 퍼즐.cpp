#include<iostream>
#include<set>
#include<queue>
using namespace std;

long long P_end;

int BFS(long long F)
{
	int m[4] = {12, -12, 4, -4}; //위 아래 왼 오 이동 방향 
	int dx[4] = {-1, 1, 0, 0}; //위 아래 왼 오
	int dy[4] = {0, 0, -1, 1};
	int count = 0;
	queue<long long> que;
	set<long long> visited; //방문을 check하는 set

	que.push(F);
	visited.insert(F);

	while(!que.empty())
	{
		int Nque = que.size(); 
		for(int n = 0; n < Nque; n++) //que의 사이즈만큼 전부 돌린 후 count++을 한다.
		{
			long long now = que.front(); //que에서 뽑아낸 모양을 now에 저장
			que.pop();
			
			if(now == P_end) //123456780 퍼즐 모양과 같다면
				return count;
			
			int zero = 0; //0이 있는 위치를 저장할 변수
			for(;now&(15LL<<zero*4);zero++); //0의 위치를 찾아내는 for문
			
			int r = 2 - zero/3;
			int c = 2 - zero%3;

			for(int i=0; i<4; i++) //4개의 움직임을 위한 for문
			{
				int pr = r + dx[i];
				int pc = c + dy[i];
				if(pr < 0 || pr > 2 || pc < 0 || pc > 2) continue; //범위 바깥이라면 continue
				
				int mv = (zero*4) + m[i];
				long long temp = now&(15LL<<mv); //바꿀 위치의 값을 뽑아 temp에 저장
				long long next = now&(~(15LL<<mv)); //바꿀 위치를 0000 으로 만들어 next에 저장
				temp = (temp>>mv)<<(zero*4); //temp를 zero 위치에 set
				next = next|temp; //zero위치에 바뀔 값을 or 한다.

				if(visited.find(next) == visited.end()) //방문한 적이 없다면 실행
				{
					que.push(next);
					visited.insert(next);
				}
			}
		}
		count++; //한 큐의 내용을 전부 수행했다면 count++
	}
	return -1; //모든 큐를 돌았지만 값이 없다면 -1
}

int main(void)
{
	long long P_start = 0;
	
	for(int i=0; i<9; i++)
	{
		int n;
		cin >> n;
		P_start = (P_start<<4)+n;
		P_end = (P_end<<4)+i;
	}
	P_end <<= 4;

	cout << BFS(P_start) << endl;
}