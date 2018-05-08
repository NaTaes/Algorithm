#include<iostream>
#include<queue>
using namespace std;

queue<pair<int, int>> que; //que�� first = ȭ�� �̸�Ƽ�� ����, second = Ŭ������ ����
int S;
int ch[1001][1001]; //ȭ�� �̸�Ƽ�� ������ Ŭ������ ������ Ȯ���� üũ

int BFS()
{
	int count=1;
	que.push(make_pair(1, 1));
	while(1)
	{
		int qsize = que.size(); //�ʴ� ����Ǵ� ��Ȳ�� ���� �ݺ��� Ȯ���Ѵ�.

		for(int i=0; i<qsize; i++)
		{
			int s = que.front().first;
			int c = que.front().second;
			que.pop();

			if(S==s) //Ȯ���ϰ��� �ϴ� �̸�Ƽ�ܰ� ������ �̸�Ƽ���� ������ ���ٸ�
				return count;

			if(ch[s][s] == 0) //(s, c) -> (s, s) Ŭ�����忡 ����(ch[s][s] Ȯ��)
			{
				que.push(make_pair(s, s));
				ch[s][s] = 1; //üũ
			}
			if(s+c <= 1000 && ch[s+c][c] == 0) //(s, c) -> (s+c, c) ȭ�鿡 ����(ch[s+c][c] Ȯ��)
			{
				que.push(make_pair(s+c, c));
				ch[s+c][c] = 1;
			}
			if(s-1 >=2 && ch[s-1][c] == 0) //(s, c) -> (s-1, c) ȭ�鿡�� -1 ����(ch[s-1][c] Ȯ��)
			{
				que.push(make_pair(s-1, c));
				ch[s-1][c] = 1;
			}
		}
		count++; //�� �������� ������ �ʸ� ������Ų��.
	}
}

int main(void)
{
	int time;
	cin >> S;

	time = BFS();

	cout << time << endl;
}