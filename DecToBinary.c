#include<stdio.h>
/*
    Converting decimal number and print it in binary formate
*/
int main()
    {   
        unsigned int num,BinNum=0,temp;

        printf("enter the number: \n");
        scanf("%u",&num);

        for(int i=(sizeof(int)*8)-1;i>=0;i--)
        {   
            if(num & (1<<i))
            {
                printf("1");
            }
            else{
                printf("0");
            }
        }
        




        return 0;
    }
