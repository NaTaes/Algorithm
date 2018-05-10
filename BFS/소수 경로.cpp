#include<iostream>
#include<queue>
using namespace std;

int B;
int divisor(int n)
{
	int count=0;
	for(int i=1; i*i <= n; i++)
		if(n%i == 0) //������ �������� ���
		{
			count++;
			if(i*i<n)
				count++;
			if(count>2) //����� ������ 3���̻��̴�(�Ҽ�x)
				return 0;
		}
	return 1; //����� ������ 2����(�Ҽ�)
}

int BFS(int n)
{
	if(n == B)
		return 0;
	queue<int> que;
	int N[10000] = {0,};
	que.push(n);
	N[n] = 1;
	while(!que.empty())
	{
		int num = que.front();
		que.pop();

		int s___ = num%1000;
		for(int i=0; i<10; i++)
		{
			s___ += i*1000;
			if(s___ >= 1000 && s___ < 10000 && N[s___] == 0) // 1000 <= �� <= 10000 �����̰�, N[s___]�� üũ���� �ʾҴٸ� ����
			{
				if(divisor(s___)) //�Ҽ��� �����Ѵ�.
				{
					if(s___ == B) //s___�� B�� ���ٸ� ���� �����Ѵ�.
						return N[num];
					que.push(s___);
					N[s___] = N[num] + 1; //���� N[num]���� N[s___]���� �̵��� ���̹Ƿ� +1�� ���ش�.
				}
			}
			s___ -= i*1000; //s___�� s��ġ�� ���� �����ϱ� ������ ������.
		}

		int _s__ = (num%100)+((num/1000)*1000);
		for(int i=0; i<10; i++)
		{
			_s__ += i*100;
			if(_s__ >= 1000 && _s__ < 10000 && N[_s__] == 0)
			{
				if(divisor(_s__))
				{
					if(_s__ == B)
						return N[num];
					que.push(_s__);
					N[_s__] = N[num] + 1;
				}
			}
			_s__ -= i*100;
		}

		int __s_ = (num%10)+((num/100)*100);
		for(int i=0; i<10; i++)
		{
			__s_ += i*10;
			if(__s_ >= 1000 && __s_ < 10000 && N[__s_] == 0)
			{
				if(divisor(__s_))
				{
					if(__s_ == B)
						return N[num];
					que.push(__s_);
					N[__s_] = N[num] + 1;
				}
			}
			__s_ -= i*10;
		}
		
		int ___s = (num/10)*10;
		for(int i=0; i<10; i++)
		{
			___s += i;
			if(___s >= 1000 && ___s < 10000 && N[___s] == 0)
			{
				if(divisor(___s))
				{
					if(___s == B)
						return N[num];
					que.push(___s);
					N[___s] = N[num] + 1;
				}
			}
			___s -= i;
		}
	}
	return -1; //que�� empty�Ǹ� B�� �� �� ���ٴ� ���̹Ƿ� -1�� �����Ѵ�.
}

int main(void)
{
	int T, A;

	cin >> T;

	while(T--)
	{
		cin >> A >> B;
		
		int t = BFS(A);
		if(t == -1)
			cout << "Impossible" << endl;
		else
			cout << t << endl;
	}
}