#include <stdio.h>
/*
Draw the following pyramid
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
*/

int main(void)
{
    int Height;

    //check the input value if it's valid or not
    do
    {
        //taking the height of the pyramid from user.
        printf("Height: ");
        scanf("%d", &Height);
    }
    while (((Height < 1) || (Height > 8)));


    //the first loop for Rows
    for (int i = 1; i <= Height; i++)
    {
        //the second loop for columns
        for (int j = 1; j <= Height; j++)
        {
            //printing condition
            if (j >= (Height - i + 1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        //print new line
        printf("\n");
    }
    return 0;

}