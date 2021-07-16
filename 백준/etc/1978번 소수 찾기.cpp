#include <iostream>
using namespace std;

int main(){
	int n, cnt=0;
	cin >> n;

	while(n--){
		int x, j;
		cin >> x;

		if (x == 2) cnt++;
		else if(x>2) 
		{
			for (j = 2; j < x ;j++)
			{
				if (x%j == 0)
					break;
			}
			if(j==x)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}
