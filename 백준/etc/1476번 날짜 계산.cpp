#include<stdio.h>

int main(){
   
	int i = 1;
	int E, S, M;
	int e = 1, s = 1, m = 1;

	scanf("%d %d %d", &E, &S, &M);

	while(1){
		if(e == E && s == S && m == M)
		{
			printf("%d\n", i);
			return 0;
		}

		e += 1;
		s += 1;
		m += 1;

		i++;

		if(e == 16)
			e = 1;
		if(s == 29)
			s = 1;
		if(m == 20)
			m = 1;
	}
}
