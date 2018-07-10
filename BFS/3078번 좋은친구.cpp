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
		if(!vque[len].empty()) //vque[len]�� ������� �ʴٸ� ����
		{
			while(i - vque[len].front()  > K) //���� K�� ���̸� ���� pop ���ش�
			{
				vque[len].pop();
				if(vque[len].empty()) //����ִٸ� �����.
					break;
			}
			//pop�� ������ �����ִ� vque[len]�� ũ��� ���� ģ���� ���� �ȴ�.
			F += vque[len].size(); //�ε����� len�� ��ġ�� vector�� size�� F�� �����ش�.
			vque[len].push(i); //���� ����� i�� push ���ش�.
		}
		else //vque[len]�� ����ִٸ� ����
			vque[len].push(i);
	}
	cout << F << endl;
}