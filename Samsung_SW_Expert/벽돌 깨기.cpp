#include <iostream>
#include <queue>

using namespace std;

int N, W, H;

int HW[15][12];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int Min_value = 192;

void StoneBreak(int Map[15][12], int sy)
{
	int s;
	for(s=0; s<H; s++) //ù ���� Ȯ��
		if(Map[s][sy] != 0) break;
	
	if(s == H) return; //������ ������ �������� �ʴ´�.

	queue<pair<int, int>> que;

	que.push(make_pair(s, sy));

	while(!que.empty()) //����� ���
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		int num = Map[x][y];
		
		if(num == 0) continue;		

		Map[x][y] = 0; //�����

		if(num == 1) continue;

		for(int i=0; i<4; i++)
		{			
			for(int j=1; j<num; j++)
			{
				int mx = x + (dx[i] * j);
				int my = y + (dy[i] * j);

				if(mx < 0 || mx > H-1 || my < 0 || my > W-1 || Map[mx][my] == 0) continue;

				que.push(make_pair(mx, my));
			}
		}
	}

	for(int i=0; i<W; i++) //��
	{
		for(int j=H-1; j>0; j--) //��
		{
			if(Map[j][i] == 0)
			{
				for(int go=j-1; go >= 0; go--)
				{
					if(Map[go][i] != 0)
					{
						Map[j][i] = Map[go][i];
						Map[go][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void Ball(int Map[15][12], int n)
{
	int tmp[15][12];

	for(int ix=0; ix<H; ix++)
		for(int jy=0; jy<W; jy++)
			tmp[ix][jy] = Map[ix][jy];

	if(n == N) //N���� ���� ������ ������ ���� ���ϱ�
	{
		int count = 0;
		for(int i=0; i<W; i++) //��
		{
			for(int j=H-1; j>=0; j--) //��
			{
				if(Map[j][i] == 0) break;
				count++;
			}
		}

		Min_value = min(Min_value, count);
		return;
	}

	for(int i=0; i<W; i++) //�� ���ο� �ߺ��� ����ؼ� ���� ������.
	{		
		//i������ ������ ���� ���� ���� �Ǵ� �Լ� ����.
		StoneBreak(tmp, i);

		Ball(tmp, n+1); //���ŵ� ���¿��� ���� ������ �Ѿ��.
		
		//tmp = Map ����
		for(int ix=0; ix<H; ix++)
			for(int jy=0; jy<W; jy++)
				tmp[ix][jy] = Map[ix][jy];
	}
}

int main(void)
{
	int T;

	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N  >> W >> H;

		for(int i=0; i<H; i++)
			for(int j=0; j<W; j++)
				cin >> HW[i][j];

		Ball(HW, 0);
	
		printf("#%d %d\n", t+1, Min_value);
		Min_value = 192;
	}

	return 0;
}