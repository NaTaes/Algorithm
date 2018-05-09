#include<iostream>
#include<string>
#include<queue>
using namespace std;

//��ũ�� �Լ��� �̿��� �ð��� ���� ��Ų��.
#define D(n) (2*n)%10000;
#define S(n) (n+9999)%10000
#define L(n) ((n%1000)*10)+(n/1000);
#define R(n) (n/10)+((n%10)*1000);

int main(void)
{
	int T, A, B;

	cin >> T;

	while(T--)
	{
		//�����ϴ� ���� ch�� que�� ���������ν� �ʱ�ȭ �ڵ带 ���� �� �ִ�.
		bool ch[10000] = {0,};
		queue<pair<int, string>> que;
		
		cin >> A >> B;
		que.push(make_pair(A, ""));
		ch[A] = 1;

		while(!que.empty())
		{
			int n = que.front().first;
			string DSLR = que.front().second;
			que.pop();

			int Dn = D(n);
			if(ch[Dn] == 0) //�湮�� ���� �ƴ϶�� �����Ѵ�.
			{
				if(Dn==B) //���� D����� ��ģ ���� B�� ���ٸ� ����� �����Ѵ�.
				{
					cout << DSLR+"D" << endl;
					break;
				}
				que.push(make_pair(Dn, DSLR + "D")); //D����� ��ģ ���� "D"���ڸ� �߰��� ���ڿ��� que�� push�Ѵ�.
				ch[Dn] = 1; //�湮�� üũ�Ѵ�.
			}

			int Sn = S(n);
			if(ch[Sn] == 0)
			{
				if(Sn==B)
				{
					cout << DSLR+"S" << endl;
					break;
				}
				que.push(make_pair(Sn, DSLR + "S"));
				ch[Sn] = 1;
			}

			int Ln = L(n);
			if(ch[Ln] == 0)
			{
				if(Ln==B)
				{
					cout << DSLR+"L" << endl;
					break;
				}
				que.push(make_pair(Ln, DSLR + "L"));
				ch[Ln] = 1;
			}

			int Rn = R(n);
			if(ch[Rn] == 0)
			{
				if(Rn==B)
				{
					cout << DSLR+"R" << endl;
					break;
				}
				que.push(make_pair(Rn, DSLR + "R"));
				ch[Rn] = 1;
			}
		}
	}
}