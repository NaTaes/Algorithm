#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<queue<int>> vque(21);
char NAME[21];

int main(void)
{
	int N, K;
	long long F = 0;
	scanf("%d %d", &N, &K);

	for(int i=0; i<N; i++)
	{
		cin >> NAME;
		int len = strlen(NAME);
		if(!vque[len].empty()) //vque[len]가 비어있지 않다면 실행
		{
			while(i - vque[len].front()  > K) //범위 K의 밖이면 전부 pop 해준다
			{
				vque[len].pop();
				if(vque[len].empty()) //비어있다면 멈춘다.
					break;
			}
			//pop이 끝난후 남아있는 vque[len]의 크기는 좋은 친구의 수가 된다.
			F += vque[len].size(); //인덱스가 len인 위치의 vector의 size를 F에 더해준다.
			vque[len].push(i); //현재 등수인 i를 push 해준다.
		}
		else //vque[len]이 비어있다면 실행
			vque[len].push(i);
	}
	cout << F << endl;
}