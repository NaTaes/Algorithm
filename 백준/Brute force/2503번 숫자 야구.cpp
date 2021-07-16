#include<iostream>
#include<vector>
using namespace std;

char ch1[3];
char ch2[3];

vector<int> vec; //주어지는 숫자, 스트라이크 갯수, 볼 갯수 __________(10bit)__(2bit)__(2bit) 14bit 사용

void pick(char tmp[3], int n) //숫자를 분해해서 배열에 삽입
{
	int i = 2;
	while(n)
	{
		tmp[i--] = n%10 + 48;
		n/=10;
	}
}

int Possible() //가능성 유무를 판별
{
	for(int n=0; n<vec.size(); n++) //주어진 숫자의 갯수만큼 반복
	{
		int temp = vec[n];
		pick(ch2, temp>>4);
		int S = (temp >> 2) & 3;
		int B = temp & 3;
		int tS = 0;
		int tB = 0;

		if(ch1[0] == ch2[0] && ch1[1] == ch2[1] && ch1[2] == ch2[2]) return 0; //3개의 숫자가 전부 같다면 제외

		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
			{
				if(i==j) { if(ch1[i] == ch2[j]) tS++; } //같은 위치 + 숫자가 같다면 스트라이크 갯수를 증가시킨다.
				else { if(ch1[i] == ch2[j]) tB++; } //다른 위치 + 숫자가 같다면 볼의 갯수를 증가시킨다.
			}
		if(S!=tS || B!=tB) return 0; //주어진 숫자의 스트라이크, 볼의 갯수와 일치하지 않으면 가능성이 없으므로 제외
	}
	return 1; //주어진 모든 수와 스트라이크, 볼의 갯수가 일치하므로 가능성있는 숫자
}

int main(void)
{
	int N, pos=0;
	int n, s, b;
	
	cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> n >> s >> b;
		vec.push_back(n<<4 | s<<2 | b);
	}

	for(int i=123; i<988; i++)
	{
		pick(ch1, i);
		if(ch1[0]==ch1[1] || ch1[0]==ch1[2] || ch1[1]==ch1[2] ||
			ch1[0]=='0' || ch1[1]=='0' || ch1[2]=='0') continue; //다른 위치에 같은 숫자가 있거나, 0이 있다면 제외
		if(Possible()) pos++; //가능성 있는 숫자라면 pos를 증가시킨다.
	}
	cout << pos << endl;
}