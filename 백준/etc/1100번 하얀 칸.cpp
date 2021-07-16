#include<iostream>
using namespace std;
char map[8][8];

int main(void)
{
	int count = 0;
	int n = 0;

	for(int i=0; i<8; i++)
		cin >> map[i];
	
	for(int i=0; i<8; i++)
	{
		for(int j=n; j<8; j+=2)
			if(map[i][j] == 'F') count++;
		n = n?0:1;
	}
	cout << count << endl;
}
