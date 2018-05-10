#include<iostream>
#include<string>
#include<queue>
using namespace std;

//매크로 함수를 이용해 시간을 단축 시킨다.
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
		//시작하는 곳에 ch와 que를 선언함으로써 초기화 코드를 없앨 수 있다.
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
			if(ch[Dn] == 0) //방문한 곳이 아니라면 실행한다.
			{
				if(Dn==B) //만약 D계산을 거친 값이 B와 같다면 출력을 실행한다.
				{
					cout << DSLR+"D" << endl;
					break;
				}
				que.push(make_pair(Dn, DSLR + "D")); //D계산을 거친 값과 "D"문자를 추가한 문자열을 que에 push한다.
				ch[Dn] = 1; //방문을 체크한다.
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
