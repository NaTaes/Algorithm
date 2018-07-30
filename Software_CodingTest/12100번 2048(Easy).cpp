#include<iostream>
using namespace std;

int Map[20][20];
bool check[20][20];
int N;
int Max;
int dx[4] = {-1, 0, 1, 0}; //��, ��, ��, ��
int dy[4] = {0, -1, 0, 1};

bool Block_Move(int arr[20][20], int dir)
{
	bool mv_ch = true; //�� �Լ��� ���� ������ ���Ѱ��� �ִ��� Ȯ���ϱ� ���� üũ bool
	int i = 0, j = 0;
	int ch = (dx[dir] + dy[dir]) * -1; //������ ��, �� �̶�� 0 ���� N-1���� �����ϴ� for��, ��, �� �̶�� N-1 ���� 0���� �����ϴ� for��
	if(dir==2 || dir == 3) //������ ��, �� �̶�� ����
	{
		i = N-1;
		j = N-1;
	}
		
	for(; i>=0 && i<N; i+=ch)
	{
		for(; j>=0 && j<N; j+=ch)
		{
			if(arr[i][j] == 0) continue;
			int mx = i; //for���� ���ư��� i, j�� �����ؾ� �ϹǷ� mx, my�� ����
			int my = j;
			if(mx+dx[dir] < 0 || my+dy[dir] < 0 || mx+dx[dir] > N-1 || my+dy[dir] > N-1) continue; //���� ����� continue
						
			while(mx+dx[dir] >= 0 && my+dy[dir] >= 0 && mx+dx[dir] < N && my+dy[dir] < N) //�ʾȿ� �������� ����
			{
				if(check[mx+dx[dir]][my+dy[dir]]) break; //üũ �� ���̶�� ���� ���ذ� �� �����Ƿ� break;

				if(arr[mx+dx[dir]][my+dy[dir]] == 0) //������ ���� 0�̶�� �̵������ش�.
				{
					arr[mx+dx[dir]][my+dy[dir]] = arr[mx][my];
					arr[mx][my] = 0;
					mx+=dx[dir]; //�̵���Ų �� mx, my�� ����
					my+=dy[dir];
					mv_ch = false; //�̵��� �����Ƿ� mv_ch�� false�� ����
					continue; //0���� �̵��� ���̹Ƿ� ��� �����Ѵ�.
				}
				
				if(arr[mx][my] == arr[mx+dx[dir]][my+dy[dir]]) //�̵��� ���� ������ġ�� ���� ���ٸ� ����
				{
					arr[mx][my]=0; //�� ��ġ 0
					mx+=dx[dir]; //��ġ ����
					my+=dy[dir];
					arr[mx][my]*=2; //������ġ�� ���� 2���
					Max = max(Max, arr[mx][my]); //Max���� Ȯ��
					check[mx][my] = true; //������ ���̹Ƿ� �ٽ� ���� �� ���� check���ش�.
					mv_ch = false; //�̵��� �����Ƿ� mv_ch�� false�� ����
					break;
				}
				else //�̵��� ���� ������ġ�� ���� �ٸ��Ƿ� �׸��Ѵ�.
					break;				
			}
		}
		j = (dir==2 || dir == 3) ? N-1 : 0; //�� i�� ���� ���� ���������Ƿ� j�� �ѹ����ش�.
	}
	return mv_ch; //���� ���� �ִٸ� false�� ����, ���� ���� ���ٸ� true�� ����
}

void Easy_Map(int arr[20][20], int dir, int count)
{
	int mv_arr[20][20];

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			mv_arr[i][j] = arr[i][j]; //�޾ƿ� �迭�� ������ �迭�� mv_arr�� �־��ش�.
			check[i][j] = false; //check�� �ٽ� �������´�.
		}

	if(Block_Move(mv_arr, dir)) return; //������ ���� true�� ���Ѱ��� �����Ƿ� ��͸� �׸��Ѵ�.
	if(count > 3) return; //3���� ũ�� �ȵǹǷ� ��͸� �׸��Ѵ�.(0, 1, 2, 3, 4) : 5ȸ

	for(int i=0; i<4; i++)
		Easy_Map(mv_arr, i, count+1); //4������ �����ش�.
}

int main(void)
{
	cin >> N;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin >> Map[i][j];
			Max = max(Max, Map[i][j]); //���� �ʿ��� ���� ū ���� �̸� Max�� �־��ش�.
		}

	for(int i=0; i<4; i++)
		Easy_Map(Map, i, 0); //�� ��ġ���� 4������ �����ش�.

	cout << Max << endl;
}