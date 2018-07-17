#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<deque<int>> deq(5); //4개의 톱니바퀴를 위한 deque
bool check[5]; //돌아간 톱니바퀴를 확인하는 check배열

void Gear_Move(int Gnum, int dir)
{
	int tmp;
	int F_R = deq[Gnum].at(2); //현재 위치에서 오른쪽 바퀴 값
	int F_L = deq[Gnum].at(6); //현재 위치에서 왼쪽 바퀴 값
	if(dir == 1) //시계 방향
	{
		tmp = deq[Gnum].back();
		deq[Gnum].pop_back();
		deq[Gnum].push_front(tmp);
	}
	else //반시계 방향
	{
		tmp = deq[Gnum].front();
		deq[Gnum].pop_front();
		deq[Gnum].push_back(tmp);
	}

	check[Gnum] = true; //돌아간 톱니로 체크

	int Gnum_R = Gnum + 1; //오른쪽
	int Gnum_L = Gnum - 1; //왼쪽
	//오른쪽은 index가 4보다 작거나 같아야하고, 돌아간적 없어야하며, 톱니가 돌기전 3시방향 값과 오른쪽톱니의 9시방향 값 다르다면 실행
	if(Gnum_R <= 4 && !check[Gnum_R] && F_R != deq[Gnum_R].at(6))
		Gear_Move(Gnum_R, dir * -1);
	//왼쪽은 index가 0보다 커야하고, 돌아간적 없어야하며, 톱니가 돌기전 9시방향 값과 왼쪽톱니의 3시방향 값 다르다면 실행
	if(Gnum_L > 0 && !check[Gnum_L] && F_L != deq[Gnum_L].at(2))
		Gear_Move(Gnum_L, dir * -1);
}

int main(void)
{
	int K, Gear, n, sum = 0;
	for(int i=1; i<5; i++)
		for(int j=0; j<8; j++)
		{
			int tmp;
			scanf("%1d", &tmp);
			deq[i].push_back(tmp);
		}
	cin >> K;
	while(K--)
	{
		cin >> Gear >> n;
		Gear_Move(Gear, n);
		
		for(int i=1; i<5; i++) //돌아간 톱니를 체크하는 배열을 리셋
			check[i] = false;
	}
	for(int i=0; i<4; i++)
		sum += deq[i+1].at(0) * (1<<i);
	cout << sum << endl;
}
