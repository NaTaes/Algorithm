#include<iostream>
using namespace std;

int DICE[6]; //DICE[0] : À­¸é, DICE[5] : ¹Ù´Ú¸é
int MAP[20][20];

int N, M, x, y;

int DICE_MOVE(int command)
{
	if(command == 1) //µ¿ 1¡æ5¡æ3¡æ0¡æ1
	{
		if(y+1 == M) return -1;
		int tmp = DICE[1];
		DICE[1] = DICE[0];
		DICE[0] = DICE[3];
		DICE[3] = DICE[5];
		DICE[5] = tmp;

		if(MAP[x][++y] == 0)
			MAP[x][y] = DICE[5];
		else
		{
			DICE[5] = MAP[x][y];
			MAP[x][y] = 0;
		}
		return DICE[0];
	}
	else if(command == 2) //¼­ 1¡ç5¡ç3¡ç0¡ç1
	{
		if(y-1 < 0) return -1;
		int tmp = DICE[1];
		DICE[1] = DICE[5];
		DICE[5] = DICE[3];
		DICE[3] = DICE[0];
		DICE[0] = tmp;

		if(MAP[x][--y] == 0)
			MAP[x][y] = DICE[5];
		else
		{
			DICE[5] = MAP[x][y];
			MAP[x][y] = 0;
		}
		return DICE[0];
	}
	else if(command == 3) //ºÏ 4¡æ5¡æ2¡æ0¡æ4
	{
		if(x-1 < 0) return -1;
		int tmp = DICE[4];
		DICE[4] = DICE[0];
		DICE[0] = DICE[2];
		DICE[2] = DICE[5];
		DICE[5] = tmp;

		if(MAP[--x][y] == 0)
			MAP[x][y] = DICE[5];
		else
		{
			DICE[5] = MAP[x][y];
			MAP[x][y] = 0;
		}
		return DICE[0];
	}
	else //³² 4¡ç5¡ç2¡ç0¡ç4
	{
		if(x+1 == N) return -1;
		int tmp = DICE[4];
		DICE[4] = DICE[5];
		DICE[5] = DICE[2];
		DICE[2] = DICE[0];
		DICE[0] = tmp;

		if(MAP[++x][y] == 0)
			MAP[x][y] = DICE[5];
		else
		{
			DICE[5] = MAP[x][y];
			MAP[x][y] = 0;
		}
		return DICE[0];
	}
}


int main(void)
{
	int K;

	cin >> N >> M >> x >> y >> K;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &MAP[i][j]);

	for(int i=0; i<K; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		int value = DICE_MOVE(cmd);
		if(value != -1)
			cout << value << endl;
	}
}