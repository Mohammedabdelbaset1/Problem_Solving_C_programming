#include<stdio.h>
#include<string.h>


int main()
{
    int count_char=0,count_sent=0,count_word=0;
    char input[]="Congratulations! Today is your day. You're off to Great Places! You're off and away! ";
    int i=0;
    while(input[i] != '\0')
    {
        
        if(((input[i]>='A') && (input[i]<='Z')) || ((input[i]>='a') && (input[i]<='z')))
        {
            count_char++;
        }
        if((input[i]=='!') || (input[i]=='.') || (input[i]=='?'))
        {
            count_sent++;
            printf("%c\n",input[i]);
        }
        if((input[i]==' '))
        {
            count_word++;
        }
        i++;
    }
    printf("the number of characters is: %d",count_char);
    printf("\nthe number of sentences is: %d",count_sent);
    printf("\nthe number of words is: %d",count_word);



    return 0;
}