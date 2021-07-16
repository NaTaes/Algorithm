#include<iostream>
#include<math.h>
using namespace std;
bool Button[10];

int check(int num)
{
	int length=0;
	if(num == 0)
		return Button[0]?0:1;
	while(num>0)
	{
		if(Button[num%10])
			return 0;
		num/=10;
		length++;
	}
	return length;
}

int main() {
	int N, M;
	int ans;
	cin >> N;
	cin >> M;
	for(int i=0; i<M; i++)
	{
		int n;
		cin >> n;
		Button[n] = 1;
	}
	ans = abs(N-100);
	for(int i=0; i<=1000000; i++)
	{
		if(check(i))
		{
			int len = check(i);
			if(ans > len+abs(N-i))
				ans = len+abs(N-i);
		}
	}
	cout << ans << endl;
}
