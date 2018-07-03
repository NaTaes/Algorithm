#include<iostream>
using namespace std;

char CAL[101];
char POSTFIX[101];

int main(void)
{
	int j=0;
	cin >> CAL;

	for(int i=0; CAL[i]!='\0'; i++) //NULL 전까지 반복한다.
	{
		if(CAL[i] >= 65 && CAL[i] <= 90) //대문자 알파벳일때, 그냥 출력한다.
			cout << CAL[i];
		else if(CAL[i] == ')') //닫는 괄호라면, 여는 괄호가 나오기 전까지 연산자를 출력한다.
		{
			while(POSTFIX[--j] != '(')
				cout << POSTFIX[j];
		}
		else if(((CAL[i] == '*' || CAL[i] == '/') && (POSTFIX[j-1] == '+' || POSTFIX[j-1] == '-')) || CAL[i] == '(') //현재 연산자가 (* or /) 이고, 스택에 top에 저장된 연산자가 (+ or -)이거나 여는 괄호라면 실행
		{
			POSTFIX[j++] = CAL[i]; //스택에 넣어준다. 연산자 순위가 (+,- < *,/) 이므로 유일하게 그냥 넣을 수 있는 상태이다.
		}
		else //연산자 일때(그냥 넣을수 있는 조건은 지나왔기 때문에 이 조건에서는 스택의 내용을 전부 뽑아낸후, 현재 연산자를 스택에 넣어준다.
		{
			if(j>0) //스택이 비어있지 않다면 실행
			{
				while(j)
				{
					j--;
					if((POSTFIX[j] == '+' || POSTFIX[j] == '-') && (CAL[i] == '*' || CAL[i] == '/')) //현재 연산자가 (* or /)일때, 스택에 연산자 순위가 더 작다면 그만 뽑아낸다.
					{
						POSTFIX[++j] = CAL[i]; //스택에 넣어준다.
						j++;
						break;
					}
					if(POSTFIX[j] == '(') //여는 괄호가 있다면, 그만 뽑아낸다.
					{
						POSTFIX[++j] = CAL[i]; //스택에 넣어준다.
						j++; //스택을 바라보는 위치를 조정한다.
						break;
					}
					cout << POSTFIX[j]; //뽑아낸다.
				}
				if(j==0) //전부 뽑아냈다면 연산자를 스택에 넣어준다.
					POSTFIX[j++] = CAL[i];
			}
			else //스택이 비어있다면 실행
				POSTFIX[j++] = CAL[i]; //스택에 넣어준다.
		}
	}
	while(j) //연산자가 스택에 남아있다면 전부 뽑아낸다.
		cout << POSTFIX[--j];
}