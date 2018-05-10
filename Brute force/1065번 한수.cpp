#include<iostream>
using namespace std;

int possible(int num)
{
	if(num < 100)
		return 1;
	int sub = num%10 - (num/10)%10;
	num/=10;
	while(num > 9)
	{
		if(sub!=num%10-(num/10)%10)
			return 0;
		num/=10;
	}
	return 1;
}

int main(void)
{
	int count = 0;
	int N;
	cin >> N;

	for(int i=1; i<=N; i++)
		count+=possible(i);
	cout << count << endl;
}
