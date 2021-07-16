#include<iostream>
#include<vector>
using namespace std;

char ch1[3];
char ch2[3];

vector<int> vec; //�־����� ����, ��Ʈ����ũ ����, �� ���� __________(10bit)__(2bit)__(2bit) 14bit ���

void pick(char tmp[3], int n) //���ڸ� �����ؼ� �迭�� ����
{
	int i = 2;
	while(n)
	{
		tmp[i--] = n%10 + 48;
		n/=10;
	}
}

int Possible() //���ɼ� ������ �Ǻ�
{
	for(int n=0; n<vec.size(); n++) //�־��� ������ ������ŭ �ݺ�
	{
		int temp = vec[n];
		pick(ch2, temp>>4);
		int S = (temp >> 2) & 3;
		int B = temp & 3;
		int tS = 0;
		int tB = 0;

		if(ch1[0] == ch2[0] && ch1[1] == ch2[1] && ch1[2] == ch2[2]) return 0; //3���� ���ڰ� ���� ���ٸ� ����

		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
			{
				if(i==j) { if(ch1[i] == ch2[j]) tS++; } //���� ��ġ + ���ڰ� ���ٸ� ��Ʈ����ũ ������ ������Ų��.
				else { if(ch1[i] == ch2[j]) tB++; } //�ٸ� ��ġ + ���ڰ� ���ٸ� ���� ������ ������Ų��.
			}
		if(S!=tS || B!=tB) return 0; //�־��� ������ ��Ʈ����ũ, ���� ������ ��ġ���� ������ ���ɼ��� �����Ƿ� ����
	}
	return 1; //�־��� ��� ���� ��Ʈ����ũ, ���� ������ ��ġ�ϹǷ� ���ɼ��ִ� ����
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
			ch1[0]=='0' || ch1[1]=='0' || ch1[2]=='0') continue; //�ٸ� ��ġ�� ���� ���ڰ� �ְų�, 0�� �ִٸ� ����
		if(Possible()) pos++; //���ɼ� �ִ� ���ڶ�� pos�� ������Ų��.
	}
	cout << pos << endl;
}