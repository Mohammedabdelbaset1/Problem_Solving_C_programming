#include<stdio.h>
/*
    reverse the binary represantation of the number 
    00000101   to  10100000 ...
    for char (1 byte) or more you can customize it by changing the #define datasize  
*/
#define datasize char

void DecToBinary(unsigned datasize n);
int main()
    {   
        unsigned datasize num,BinNum=0;

        printf("enter the number: ");
        scanf("%u",&num);
        
        for(int i=0,j=((sizeof(datasize)*8)-1);i<(sizeof(datasize)*8);i++,j--)
        {   
            
            if(num & (1<<i))
            {
                BinNum=BinNum|(1<<j);
            }
            
            
            
        }
        printf("%u\n",num);
        DecToBinary(num);
        printf("\n");
        printf("%u\n",BinNum);
        DecToBinary(BinNum);


        




        return 0;
    }

    void DecToBinary(unsigned datasize n)
    {
        for(int i=(sizeof(datasize)*8)-1;i>=0;i--)
        {   
            if(n & (1<<i))
            {
                printf("1");
            }
            else{
                printf("0");
            }
        }

    }
