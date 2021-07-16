#include<iostream>
using namespace std;

int STACK[10001];
char order[5];

int main(void)
{
	int N, index = 0;
	scanf("%d", &N);

	while(N--)
	{
		scanf("%s", order);
		if(order[1] == 'u') scanf("%d", &STACK[index++]); //push
		else if(order[0] == 'p') printf("%d\n", index ? STACK[--index] : -1); //pop
		else if(order[0] == 's') printf("%d\n", index); //size
		else if(order[0] == 'e') printf("%d\n", index ? 0 : 1); //empty
		else printf("%d\n", index ? STACK[index-1] : -1); //top
	}
}