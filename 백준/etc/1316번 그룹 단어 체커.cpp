#include<iostream>
using namespace std;
char S[101];
int ch[26];
int main(void)
{
	int N, count=0;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> S;

		int j = 0;
		while(S[j]!='\0')
		{
			if(ch[S[j]-'a'] == 0)
			{
				ch[S[j]-'a'] = 1;
				j++;
				continue;
			}
			if(S[j] == S[j-1])
			{
				j++;
				continue;
			}
			if(ch[S[j]-'a'] != 0)
				break;
			j++;
		}
		if(S[j]=='\0')
			count++;
		for(int n = 0; n < 26; n++)
			ch[n] = 0;
	}

	cout << count << endl;
}
