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
			if(ta == a && tb == b) //원하는 물의 양이 되면 출력
				return count;

			//F(A)
			if(visited.find(make_pair(A, tb)) == visited.end()) //무조건 채우는 것으로 채우고 방문 확인
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
			if(visited.find(make_pair(0, tb)) == visited.end()) //무조건 비우는 것으로 0으로 만들고 방문 확인
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
			if(B-tb != 0) // B가 채워진 상태라면 수행하지 않는다
			{
				if(B-tb > ta) //B에 채울 공간이 더 크면 A는 비워지고 B에는 추가된다
				{
					if(visited.find(make_pair(0, tb+ta)) == visited.end())
					{
						visited.insert(make_pair(0, tb+ta));
						que.push(make_pair(0, tb+ta));
					}
				}
				else //B에 채울 공간이 더 작으므로 B는 가득차고 A는 B에 넣은만큼만 비워진다
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
		count++; //한 que가 끝나면 count를 증가시킨다.
	}
	return -1; //원하는 물의 양을 찾아내지 못하면 -1을 리턴한다.
}

int main(void)
{
	cin >> A >> B >> a >> b;
	
	cout << BFS(0, 0) << endl;
}