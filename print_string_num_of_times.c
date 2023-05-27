#include<stdio.h>
/* 
A string in the formate   XXXX,num_of_times,XXXX,num_of_times
here XXXX will be printed number of times mensioned after comma 
*/

int main(void)
{
    char s[50];
    printf("Enter the string followed by the number of times to print in the format xxxx,num,xxxx,num :");
    scanf("%s", s);

    //printf("%s\n", s);
    int i = 0;
    int Start = 0,End = 0,num=0;

    while (s[i])
    {
        if(((s[Start] >= 'a') && (s[Start] <= 'z')) || ((s[Start] >= 'A') && (s[Start] <= 'Z')))
        {
            while (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')))
            {
                i++;
            }
            End = i;
            if(s[i]==',')
            {
                i++;
                while ((s[i] >= '0') && (s[i] <= '9'))
                {
                    num = num * 10 + s[i] - '0'; 
                    i++;
                }
            }
            else
            {
                printf("wrong format \n");
                return 1;
            }

        }  
        else
        {
            printf("wrong format \n");
            return 1;
        }
        while(num)
        {
            for (int j = Start;j < End; j++) 
            {
                printf("%c",s[j]);
                
            }
            printf("\n");
            num--;
        }
        i++;
        Start = i;

    }
    return 0;
}