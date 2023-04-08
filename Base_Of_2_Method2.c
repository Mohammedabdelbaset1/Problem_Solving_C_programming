// method#3
#include <stdio.h>
/* Identify if input number is Base of 2 or not */
int main()
{
    unsigned num = 0, flag, counter = 0;
    while (1)
    {
        counter = 0;
        printf("Enter the number within the range of unsigned integer\n ");
        scanf("%d", &num);
        for (int i = 0; i < 32; i++)
        {
            if (num & (1 << i))
            {
                counter++;
            }
        }
        if (counter == 1)
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