
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
/* 
A string in the formate   XXXX,num_of_times,XXXX,num_of_times
here XXXX will be printed number of times mensioned after comma 
*/

/*Define*/
#define Max_Num_of_words 10
#define Max_string_length 50
#define Max_Num_of_char 20
typedef struct word
{
    char * char_of_word;
    int num_of_times; 
} 
word;

/* FUNC Prototype*/
char ** string_parsing(char *str,int tokens, char delim,int * delim_count);
int Num_of_tokens(char* str);
void print_string_mult_of_times(word * ptr[],int num_of_elements);
int str_Len(char * str);
int str_num(char *str);



/* Global Variable*/
word * word_ptr[Max_Num_of_words];
char str[Max_string_length];


int main(void)
{
    printf("Enter the string followed by the number of times to print in the format xxxx,num,xxxx,num :");
    //scanf("%s", str);
    gets(str);
    int delim_count = 0;
    int len = str_Len(str);
    int Tokens_num = Num_of_tokens(str);
    char ** temp = string_parsing(str,Tokens_num,',',&delim_count);
    
    //printf("del = %d\n",delim_count);
    //printf("ToK =%d\n",Tokens_num);
    //printf("len = %d\n ",len);
    
    if((temp == NULL) || (Tokens_num == -1) || (len == 0) ||(delim_count != Tokens_num - 1 ))
    {
        printf("Format error \n");
        return 1;
    }
    for (int i = 0; i < Max_Num_of_words; i++)
    {
        word_ptr[i] = (word *) calloc(1,sizeof(word));
        if(word_ptr == NULL)
        {
            return 1;
        }
    }
    
    for(int i = 0,j = 1,counter = 0;(counter < Tokens_num / 2); i+=2,j+=2)
    {
        word_ptr[counter]->char_of_word = temp[i];
        word_ptr[counter]->num_of_times = str_num(temp[j]);
        if(word_ptr[counter]->num_of_times == -1)
        {
            printf("Error Negative numbers not allowed\n");
            return 1;
        }
        counter ++;
    }

    print_string_mult_of_times(word_ptr,Tokens_num);
    for (int i = 0;i < Tokens_num;i++)
    {
        free(temp[i]);
    }
    free(temp);
    for (int i = 0; i < Max_Num_of_words; i++)
    {
        free(word_ptr[i]);
    }   
            
    return 0;
}


char ** string_parsing(char * str,int tokens, char delim, int * delim_count)
{
    char ** str_ptr = (char **)calloc(Max_Num_of_char,sizeof(char *));
    if (str_ptr == NULL)
    {
        return str_ptr;
    }

    int i = 0, m = 0;
   for(int k = 0;k < tokens;k++)
   {
        str_ptr[k]= (char *)calloc(Max_Num_of_char,sizeof(char));
        if(str_ptr[k] == NULL)
        {
            return str_ptr;
        }
   }
   
    for (int j = 0; str[j] != '\0';j++)
    {
        if(str[j] == delim)
        {
           (*delim_count) ++;
            i++;
            m=0;
            continue ;
        }
        str_ptr[i][m] = str[j];
        m++;

        if(i >= tokens )
        {
            break;
        }
        
    }

    return str_ptr;

}

int Num_of_tokens(char * str)
{
    int i = 0, counter = 0;
    while (str[i])
    {
        if(str[i] == ',' || str[i+1] == '\0')
        {
            counter ++;
        }
        i++;
    }
    if (counter == 0)
    {
        return -1;
    }
    return counter;
}

void print_string_mult_of_times(word * ptr[],int num_of_elements)
{
    for (int i = 0;(i < num_of_elements / 2); i++)
    {
        for(int j = 0 ; j < ptr[i]->num_of_times ;j++)
        {
            printf("%s\n",ptr[i]->char_of_word);
        }
    }

}
int str_Len(char * str)
{
    int i = 0,counter = 0;
    while (str[i] != '\0')
    {
        counter ++;
        i++;

    }

    return counter;
}

int str_num(char *str)
{

    int len =str_Len(str),num = 0;


    for(int i = 0; i < len; i++)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            num = num * 10 + str[i] - '0';
        }
        else
        {
            return -1;
        }
        
    }


    return num;
}