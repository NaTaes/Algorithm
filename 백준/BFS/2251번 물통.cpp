#include<iostream>
#include<queue>
#include<set>
using namespace std;

queue<int> que;
set<int> visited;
set<int> R;

int main(void)
{
	int A, B, C; // _________(9bit)_________(9bit)_________(9bit) 27bit�� ���

	cin >> A >> B >> C;

	que.push(C);
	visited.insert(C);
	R.insert(C);
	while(!que.empty())
	{
		int ABC = que.front();
		que.pop();

		int tmpA = (ABC&(511<<18))>>18; //tmpA = A�� ����ִ� ���� ��
		int tmpB = (ABC&(511<<9))>>9; //tmpB = B�� ����ִ� ���� ��
		int tmpC = ABC&511; //tmpC = C�� ����ִ� ���� ��

		if(tmpA>0) //A->B || A->C //A�� ���� ä���� �ִٸ� �����Ѵ�
		{
			int TA = tmpA;
			int TB = tmpB;

			if(B-TB != 0) //B�� ���� ä���� ���� �ʴٸ� �����Ѵ�
			{
				if(B-TB < TA) //B�� ä���� ���� ���� A�� ���� �纸�� �۴ٸ� B�� ���� ä��� A�� ä�ŭ�� ����.
				{
					TA-=(B-TB);
					TB=B;
				}
				else //B�� ä���� ���� ���� A�� ���� �纸�� ũ�ٸ� A�� ������� B�� A�� ���� ���� �߰��� ä���.
				{
					TB+=TA;
					TA=0;
				}
				int TABC = (ABC&~(511<<18))|(TA<<18); //A�� ���� ���
				TABC = (TABC&~(511<<9))|(TB<<9); //B�� ���� ���� �����Ѵ�.

				if(visited.find(TABC) == visited.end()) //������ ���� ����� check �Ǿ� ���� �ʴٸ� �����Ѵ�.
				{
					que.push(TABC);
					visited.insert(TABC);
					if((TABC&(511<<18)) == 0 && R.find(TABC&511) == R.end()) //A�� ���� ���� 0�̰� C�� ���� ���� check �Ǿ� ���� �ʴٸ� �����Ѵ�.
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