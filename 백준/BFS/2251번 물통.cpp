#include<iostream>
#include<queue>
#include<set>
using namespace std;

queue<int> que;
set<int> visited;
set<int> R;

int main(void)
{
	int A, B, C; // _________(9bit)_________(9bit)_________(9bit) 27bit를 사용

	cin >> A >> B >> C;

	que.push(C);
	visited.insert(C);
	R.insert(C);
	while(!que.empty())
	{
		int ABC = que.front();
		que.pop();

		int tmpA = (ABC&(511<<18))>>18; //tmpA = A에 들어있는 물의 양
		int tmpB = (ABC&(511<<9))>>9; //tmpB = B에 들어있는 물의 양
		int tmpC = ABC&511; //tmpC = C에 들어있는 물의 양

		if(tmpA>0) //A->B || A->C //A에 물이 채워져 있다면 실행한다
		{
			int TA = tmpA;
			int TB = tmpB;

			if(B-TB != 0) //B가 가득 채워져 있지 않다면 실행한다
			{
				if(B-TB < TA) //B에 채워진 물의 양이 A의 물의 양보다 작다면 B는 가득 채우고 A는 채운만큼을 뺀다.
				{
					TA-=(B-TB);
					TB=B;
				}
				else //B에 채워진 물의 양이 A의 물의 양보다 크다면 A는 비워지고 B는 A의 물의 양을 추가로 채운다.
				{
					TB+=TA;
					TA=0;
				}
				int TABC = (ABC&~(511<<18))|(TA<<18); //A의 물의 양과
				TABC = (TABC&~(511<<9))|(TB<<9); //B의 물의 양을 수정한다.

				if(visited.find(TABC) == visited.end()) //수정한 물의 양들이 check 되어 있지 않다면 실행한다.
				{
					que.push(TABC);
					visited.insert(TABC);
					if((TABC&(511<<18)) == 0 && R.find(TABC&511) == R.end()) //A의 물의 양이 0이고 C의 물의 양이 check 되어 있지 않다면 실행한다.
							R.insert(TABC&511);
				}
			}

			TA = tmpA;
			int TC = tmpC;

			if(C-TC != 0)
			{
				if(C-TC < TA)
				{
					TA-=(C-TC);
					TC=C;
				}
				else
				{
					TC+=TA;
					TA=0;
				}
				int TABC = (ABC&~(511<<18))|(TA<<18);
				TABC = (TABC&~511)|TC;

				if(visited.find(TABC) == visited.end())
				{
					que.push(TABC);
					visited.insert(TABC);
					if((TABC&(511<<18)) == 0 && R.find(TABC&511) == R.end())
							R.insert(TABC&511);
				}
			}
		}

		if(tmpB>0) //B->A || B->C
		{
			int TA = tmpA;
			int TB = tmpB;

			if(A-TA != 0)
			{
				if(A-TA < TB)
				{
					TB-=(A-TA);
					TA=A;
				}
				else
				{
					TA+=TB;
					TB=0;
				}
				int TABC = (ABC&~(511<<18))|(TA<<18);
				TABC = (TABC&~(511<<9))|(TB<<9);

				if(visited.find(TABC) == visited.end())
				{
					que.push(TABC);
					visited.insert(TABC);
					if((TABC&(511<<18)) == 0 && R.find(TABC&511) == R.end())
							R.insert(TABC&511);
				}
			}

			TB = tmpB;
			int TC = tmpC;

			if(C-TC != 0)
			{
				if(C-TC < TB)
				{
					TB-=(C-TC);
					TC=C;
				}
				else
				{
					TC+=TB;
					TB=0;
				}
				int TABC = (ABC&~(511<<9))|(TB<<9);
				TABC = (TABC&~511)|TC;

				if(visited.find(TABC) == visited.end())
				{
					que.push(TABC);
					visited.insert(TABC);
					if((TABC&(511<<18)) == 0 && R.find(TABC&511) == R.end())
							R.insert(TABC&511);
				}
			}
		}

		if(tmpC>0) //C->A || C->B
		{
			int TA = tmpA;
			int TC = tmpC;

			if(A-TA != 0)
			{
				if(A-TA < TC)
				{
					TC-=(A-TA);
					TA=A;
				}
				else
				{
					TA+=TC;
					TC=0;
				}
				int TABC = (ABC&~(511<<18))|(TA<<18);
				TABC = (TABC&~511)|TC;

				if(visited.find(TABC) == visited.end())
				{
					que.push(TABC);
					visited.insert(TABC);
					if((TABC&(511<<18)) == 0 && R.find(TABC&511) == R.end())
							R.insert(TABC&511);
				}
			}

			TC = tmpC;
			int TB = tmpB;

			if(B-TB != 0)
			{
				if(B-TB < TC)
				{
					TC-=(B-TB);
					TB=B;
				}
				else
				{
					TB+=TC;
					TC=0;
				}
				int TABC = (ABC&~(511<<9))|(TB<<9);
				TABC = (TABC&~511)|TC;

				if(visited.find(TABC) == visited.end())
				{
					que.push(TABC);
					visited.insert(TABC);
					if((TABC&(511<<18)) == 0 && R.find(TABC&511) == R.end())
							R.insert(TABC&511);
				}
			}
		}
	}
	set<int>::iterator iter;
	for(iter=R.begin(); iter!=R.end(); iter++)
		cout << *iter << " ";
}