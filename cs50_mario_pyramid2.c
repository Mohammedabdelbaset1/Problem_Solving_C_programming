#include <stdio.h>
/*
    Draw the following pyramid
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

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
    for (int i = 0; i < Height; i++)
    {
        //the second loop for columns
        for (int j = 0; j < ((2 * Height) + 2); j++)
        {
            //printing condition
            if (((j < Height) && (j >= (Height - i - 1))) || ((j >= Height + 2) && (j <= (Height + i + 2))))
            {
                printf("#");
            }
            else
            {
                if (!(j >= (Height + i + 2)))
                {
                    printf(" ");
                }

            }
        }
        //print new line
        printf("\n");
    }
    return 0;

}