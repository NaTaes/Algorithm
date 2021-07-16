#include<iostream>
using namespace std;

int QUEUE[10001];
char order[5];

int main(void)
{
	int N, index_f = 0, index_b = 0;
	scanf("%d", &N);

	while(N--)
	{
		scanf("%s", order);
		if(order[1] == 'u') scanf("%d", &QUEUE[index_b++]); //push
		else if(order[0] == 'p') printf("%d\n", index_f != index_b ? QUEUE[index_f++] : -1); //pop
		else if(order[0] == 's') printf("%d\n", index_b-index_f); //size
		else if(order[0] == 'e') printf("%d\n", index_f == index_b ? 1 : 0); //empty
		else if(order[0] == 'f') printf("%d\n", index_f != index_b ? QUEUE[index_f] : -1); //front
		else printf("%d\n", index_f != index_b ? QUEUE[index_b-1] : -1); //back
	}
}