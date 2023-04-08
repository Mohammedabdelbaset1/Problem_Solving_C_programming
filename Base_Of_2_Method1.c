#include <stdio.h>
#include<math.h>
/* Identify if input number is Base of 2 or not*/
int main()
{ 
    unsigned num=0,flag,counter=0,limit;
   while(1)
   {
        flag = 0;
        limit = 0;
        printf("Enter the number within the range of unsigned integer\n ");
        scanf("%d",&num);
  
        for (int i = 0;(i < 32) && (flag == 0) && num >= limit; i++)
        {
            flag = !(num ^ (1 << i));
            limit = pow(2,i);//1024
            printf("flag %d\n",limit);
        }
        if (flag != 0)
        {
            printf("the num is base of 2\n");
        }   
        else
        {
            printf("the num is not base of 2\n");
        }
       
   }
   return 0;
}