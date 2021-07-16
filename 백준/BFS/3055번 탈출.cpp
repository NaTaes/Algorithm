#include<iostream>
#include<queue>
using namespace std;

char RC[50][50];
int dx[4] = {-1, 1, 0, 0}; //�����¿�
int dy[4] = {0, 0, -1, 1};
int R, C;
int Dx, Dy;

queue<pair<int, int>> gque; //����ġ queue
queue<pair<int, int>> wque; //�� queue

int BFS()
{
	int count = 0;
	while(!gque.empty())
	{
		int qsize = gque.size();
		int wsize = wque.size();

		while(qsize--) //����ġ�� que�� ���� ������.
		{
			int x = gque.front().first;
			int y = gque.front().second;
			gque.pop();

			if(x == Dx && y == Dy) //D�� ��ġ�� ���ٸ� return
				return count;

			if(RC[x][y] != 'S') //�ڽ��� 'S'�� �ƴ϶�� ���� ���� �����̹Ƿ� continue
				continue;

			for(int i=0; i<4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if(mx < 0 || mx > R-1 || my < 0 || my > C-1) continue;
				if(RC[mx][my] == '.' || RC[mx][my] == 'D') //�̵��� ��ġ�� . �̰ų� D��� ����
				{
					RC[mx][my] = 'S';
					gque.push(make_pair(mx, my));
				}
			}
		}
		while(wsize--) //���� que�� ���� ������.
		{
			int x = wque.front().first;
			int y = wque.front().second;
			wque.pop();

			for(int i=0; i<4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if(mx < 0 || mx > R-1 || my < 0 || my > C-1) continue;
				if(RC[mx][my] == 'D' || RC[mx][my] == 'X' || RC[mx][my] == '*') continue; //�̵��� ��ġ�� D, X, * ��� continue
				RC[mx][my] = '*';
				wque.push(make_pair(mx, my));
			}
		}
		count++; //�ð��� ����
	}
	return -1;
}

int main()
{
	cin >> R >> C;

	for(int i=0; i<R; i++)
	{
		scanf("\n");
		for(int j=0; j<C; j++)
		{
			scanf("%c", &RC[i][j]);

			if(RC[i][j] == '*')
				wque.push(make_pair(i, j));
			else if(RC[i][j] == 'S')
				gque.push(make_pair(i, j));
			else if(RC[i][j] == 'D')
			{
				Dx = i;
				Dy = j;
			}
		}
	}
	int result = BFS();

	if(result == -1)
	{
		cout << "KAKTUS" << endl;
		return 0;
	}

	cout << result << endl;
}