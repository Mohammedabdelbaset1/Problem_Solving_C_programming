#include<stdio.h>

/*
    count the maximum number of zeros between 2 consequtive 1's in binary representation of the number
    1000100101    the maximum number of zeros is 3 ...

*/

int main()
{   
    unsigned int num,i,j;
    int counti=0,countj=0,ZerosCount=0;
    int temp1,temp2,temp3;
    printf("Enter Num: ");
    scanf("%u",&num);

    if((num == 0) || ((num & (num-1) ) == 0))
    {
        printf("number is zero or power of 2 has no 1's or only 1 bit with 1\n");
        return -1;
    }
    

    for( i=0 ;i<(sizeof(int)*8);i++)
    {
        counti++;
        temp1=((num>>i) & 1);
        if(((num>>i) & 1))
        {   

            break;
        }
    }
    ZerosCount = 0; countj = counti;
    for(j=i+1;j<(sizeof(int)*8);j++)
    {
        countj ++;
        temp2=((num>>j) & 1);
        if(((num>>j) & 1))
        {
            temp3=(countj-counti-1);
            if((ZerosCount<= (countj-counti-1)))
            {
                ZerosCount= countj-counti-1;
            }
            counti=countj;
        }

    }

    printf("%u",ZerosCount);
    return 0;
}
