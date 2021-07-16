#include<iostream>
using namespace std;

int Cdd[1000000];

int main(void)
{
	int N, B, C;
	long long min = 0;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &Cdd[i]);

	scanf("%d %d", &B, &C);

	for(int i=0; i<N; i++)
	{
		int tmp = Cdd[i] - B; //총감독관의 수를 빼준다.
		min += 1; //인원 추가
		if(tmp <= 0) continue; //총감독관만으로 인원을 감독할 수있다면 continue한다.

		if(tmp%C) //남은 인원수를 나눈 나머지가 있다면 나눈 값에 +1을 해준다.
			min += tmp/C + 1;
		else //나머지가 없다면 딱 나눠진만큼이므로 나눈값만 더해준다.
			min += tmp/C;
	}

	printf("%lld\n", min);
}