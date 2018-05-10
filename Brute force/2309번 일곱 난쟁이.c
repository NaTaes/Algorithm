#include<stdio.h>

int main(){
    int hobit[9];
    int i, j, sum=0;
    int temp;
    
    for(i=0; i < 9; i++)
    {
        scanf("%d", &hobit[i]);
        sum += hobit[i];
    }
    
    for(i=0; i<8; i++)
    {
        for(j=i+1; j<9; j++)
        {
            if(hobit[i] > hobit[j])
            {
                temp = hobit[j];
                hobit[j] = hobit[i];
                hobit[i] = temp;
            }      
        }
    }
    
    for(i = 0; i<8; i++)
    {
        for(j=i+1; j<9; j++)
        {
            if(sum - hobit[i] - hobit[j] == 100)
            {
                for(temp = 0; temp<9; temp++)
                {
                    if(temp != i && temp != j)
                        printf("%d\n", hobit[temp]);
                }
                return 0;
            }
        }
    }
    return 0;
}
