#include<iostream>
#include<queue>
#include<set>
using namespace std;

int A, B, a, b;

queue<pair<int, int>> que;
set<pair<int, int>> visited;

int BFS(int ba, int bb)
{
	int count = 0;
	que.push(make_pair(ba, bb));
	visited.insert(make_pair(ba, bb));

	while(!que.empty())
	{
		int qsize = que.size();
		for(int i=0; i<qsize; i++)
		{
			int ta = que.front().first;
			int tb = que.front().second;
			que.pop();
			if(ta == a && tb == b) //���ϴ� ���� ���� �Ǹ� ���
				return count;

			//F(A)
			if(visited.find(make_pair(A, tb)) == visited.end()) //������ ä��� ������ ä��� �湮 Ȯ��
			{
				visited.insert(make_pair(A, tb));
				que.push(make_pair(A, tb));
			}
			//F(B)
			if(visited.find(make_pair(ta, B)) == visited.end())
			{
				visited.insert(make_pair(ta, B));
				que.push(make_pair(ta, B));
			}

			//E(A)
			if(visited.find(make_pair(0, tb)) == visited.end()) //������ ���� ������ 0���� ����� �湮 Ȯ��
			{
				visited.insert(make_pair(0, tb));
				que.push(make_pair(0, tb));
			}
			//E(B)
			if(visited.find(make_pair(ta, 0)) == visited.end())
			{
				visited.insert(make_pair(ta, 0));
				que.push(make_pair(ta, 0));
			}

			//M(A,B) A->B
			if(B-tb != 0) // B�� ä���� ���¶�� �������� �ʴ´�
			{
				if(B-tb > ta) //B�� ä�� ������ �� ũ�� A�� ������� B���� �߰��ȴ�
				{
					if(visited.find(make_pair(0, tb+ta)) == visited.end())
					{
						visited.insert(make_pair(0, tb+ta));
						que.push(make_pair(0, tb+ta));
					}
				}
				else //B�� ä�� ������ �� �����Ƿ� B�� �������� A�� B�� ������ŭ�� �������
				{
					if(visited.find(make_pair(ta-(B-tb), B)) == visited.end())
					{
						visited.insert(make_pair(ta-(B-tb), B));
						que.push(make_pair(ta-(B-tb), B));
					}
				}
			}

			//M(B,A) B->A
			if(A-ta != 0)
			{
				if(A-ta > tb)
				{
					if(visited.find(make_pair(ta+tb, 0)) == visited.end())
					{
						visited.insert(make_pair(ta+tb, 0));
						que.push(make_pair(ta+tb, 0));
					}
				}
				else
				{
					if(visited.find(make_pair(A, tb-(A-ta))) == visited.end())
					{
						visited.insert(make_pair(A, tb-(A-ta)));
						que.push(make_pair(A, tb-(A-ta)));
					}
				}
			}
		}
		count++; //�� que�� ������ count�� ������Ų��.
	}
	return -1; //���ϴ� ���� ���� ã�Ƴ��� ���ϸ� -1�� �����Ѵ�.
}

int main(void)
{
	cin >> A >> B >> a >> b;
	
	cout << BFS(0, 0) << endl;
}