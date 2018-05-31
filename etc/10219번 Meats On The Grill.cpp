#include<iostream>
using namespace std;
char grill[11][11];
char temp[11][11];

int main() {
	int T, H, W;

	cin >> T;
	for(int i=0; i<T; i++)
	{cin >> H >> W;

	for(int i=0; i<H; i++)
		cin >> grill[i];

	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
		{
			temp[i][W-j-1] = grill[i][j];
		}

		for(int i=0; i<H; i++)
		{
			for(int j=0; j<W; j++)
				cout << temp[i][j];
			cout << endl;
		}
	}
}
