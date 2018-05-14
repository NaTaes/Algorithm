#include<iostream>
#include<set>
#include<queue>
using namespace std;

long long P_end;

int BFS(long long F)
{
	int m[4] = {12, -12, 4, -4}; //�� �Ʒ� �� �� �̵� ���� 
	int dx[4] = {-1, 1, 0, 0}; //�� �Ʒ� �� ��
	int dy[4] = {0, 0, -1, 1};
	int count = 0;
	queue<long long> que;
	set<long long> visited; //�湮�� check�ϴ� set

	que.push(F);
	visited.insert(F);

	while(!que.empty())
	{
		int Nque = que.size(); 
		for(int n = 0; n < Nque; n++) //que�� �����ŭ ���� ���� �� count++�� �Ѵ�.
		{
			long long now = que.front(); //que���� �̾Ƴ� ����� now�� ����
			que.pop();
			
			if(now == P_end) //123456780 ���� ���� ���ٸ�
				return count;
			
			int zero = 0; //0�� �ִ� ��ġ�� ������ ����
			for(;now&(15LL<<zero*4);zero++); //0�� ��ġ�� ã�Ƴ��� for��
			
			int r = 2 - zero/3;
			int c = 2 - zero%3;

			for(int i=0; i<4; i++) //4���� �������� ���� for��
			{
				int pr = r + dx[i];
				int pc = c + dy[i];
				if(pr < 0 || pr > 2 || pc < 0 || pc > 2) continue; //���� �ٱ��̶�� continue
				
				int mv = (zero*4) + m[i];
				long long temp = now&(15LL<<mv); //�ٲ� ��ġ�� ���� �̾� temp�� ����
				long long next = now&(~(15LL<<mv)); //�ٲ� ��ġ�� 0000 ���� ����� next�� ����
				temp = (temp>>mv)<<(zero*4); //temp�� zero ��ġ�� set
				next = next|temp; //zero��ġ�� �ٲ� ���� or �Ѵ�.

				if(visited.find(next) == visited.end()) //�湮�� ���� ���ٸ� ����
				{
					que.push(next);
					visited.insert(next);
				}
			}
		}
		count++; //�� ť�� ������ ���� �����ߴٸ� count++
	}
	return -1; //��� ť�� �������� ���� ���ٸ� -1
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