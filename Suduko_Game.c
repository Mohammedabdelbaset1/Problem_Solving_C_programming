/**************************Header Files*******************************/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
/*****************************Define**********************************/
#define N 9
#define minimum_num_of_clues 17
#define maximum_num_of_clues 77
/**************************Data Types*********************************/
int  Board[N][N] = {
                         6,9,7,4,3,5,2,1,8,
                         8,5,1,7,9,2,4,6,3,
                         4,2,3,8,1,6,5,7,9,
                         1,7,6,5,8,4,3,9,2,
                         9,3,4,1,2,7,8,5,6,
                         5,8,2,3,6,9,7,4,1,
                         7,6,9,2,4,3,1,8,5,
                         2,4,8,9,5,1,6,3,7,
                         3,1,5,6,7,8,9,2,4
                        };
int Solved_Board[N][N]={
                         6,9,7,4,3,5,2,1,8,
                         8,5,1,7,9,2,4,6,3,
                         4,2,3,8,1,6,5,7,9,
                         1,7,6,5,8,4,3,9,2,
                         9,3,4,1,2,7,8,5,6,
                         5,8,2,3,6,9,7,4,1,
                         7,6,9,2,4,3,1,8,5,
                         2,4,8,9,5,1,6,3,7,
                         3,1,5,6,7,8,9,2,4
                        };
int Num_of_clues;
int Rest_of_empty_Clues;
typedef enum Error
{
    OK ,
    WRONG ,
    INVALID ,
    forbidden ,

}Error;

typedef enum Bool
{
    FALSE ,
    TRUE ,

}Bool;

/**************************Function prototypes***************************/
void Suduko_print_pattern(int Board[N][N]);
int Suduko_Generate_pattern(int Board[N][N],int Solved_Board[N][N]);
Error Suduko(int Board[N][N]);
Error Sudoku_check_Row_Col_Block(int r , int c , int  Board[N][N], int num);

/**************************Function Definitions***************************/
int main() 
{
    Error e;
    //Suduko_Generate_pattern(Board);
    Num_of_clues = Suduko_Generate_pattern(Board,Solved_Board);
    Rest_of_empty_Clues = Num_of_clues;
    while(1)
    {
        e = Suduko(Board);
        if(e == OK)
        {
            
            system("cls");
            printf("\x1b[32m");
            printf("Well Done\n");
            printf("\x1b[0m");
        }
        else if(e == WRONG)
        {
            printf("\x1b[31m");
            printf("Wrong Input\n");
            printf("\x1b[0m");
        }

        if (Rest_of_empty_Clues == 0)
        {
            printf("\x1b[32m");
            printf("Congratulations Suduko Solved Successfully \n");
            printf("\x1b[0m");

            break;
            
        }
        
    }
    return 0;
}

Error Suduko(int Board[N][N])
{
             int num ;
             int row,col;

             Error error_Row_Col_Block = OK, error;
             do
             {
                error = OK;
                Suduko_print_pattern(Board);
                printf("Enter No. of Row ");
                scanf("%d",&row);
                if(row < 0 || row > N)
                    {
                        printf("forbidden Input \n");
                        error = forbidden;
                        
                    }
                
                    printf("Enter No. of Col ");
                    scanf("%d",&col);
                    if(col < 0 || col > N)
                    {
                        printf("forbidden Input \n");
                        error = forbidden;    
                        
                    }
                    if(Board[row][col] != 0)
                    {
                        printf("invalid place \n");
                        error = INVALID;
                        
                    }
             } while (error != OK);
                    printf("Enter No. ");
                    scanf("%d",&num);
                    error_Row_Col_Block = Sudoku_check_Row_Col_Block(row , col, Board, num);

                    if((error_Row_Col_Block == OK) && (num == Solved_Board[row][col]))
                    {
                        Board[row][col] = num;
                        Rest_of_empty_Clues --;
                    

                    }
                    else
                    {
                        //printf("wrong Inputc \n");
                        error = WRONG;
                    }
    return error;
}
void Suduko_print_pattern(int Board[N][N])
{
     
    printf(" R/C|  0  1  2 |  3  4  5 |  6  7  8 |\n");
    for(int i = 0; i < N; i++)
    {
        if(i == 0 || i == 3 || i == 6)
        {
            printf("____|________________________________|\n");
        }
        for(int j = 0; j < N; j++)
        {
            if(j == 0)
                {
                     printf("%3d",i);
                }
            
            if(j == 0||j == 3||j == 6)
                 {
                     printf(" |");
                 }
            
            {
                if(Board[i][j] == 0)
                {
                    printf("\x1b[35m");
                    printf("%3c",'X');
                    printf("\x1b[0m");
                }
                else
                {
                     
                    printf("%3d",Board[i][j]);
                    printf("\a");
                }
                 
            }
        }
         printf(" |");
         printf("\n");
    }
    printf("___________________________________\n");
}

Error Sudoku_check_Row_Col_Block(int r , int c , int  Board[N][N], int num)
{
    Error error = OK;
    int StartRow = r/3*3;
    int StartCol = c/3*3;
    int Row_bound = StartRow + 3;
    int Col_bound = StartCol + 3;
    for(int i = StartRow ; i < Row_bound; i++)
    {
        for(int j = StartCol ; j < Col_bound; j++)
        {
            if(Board[i][j] == num)
            {
                error = WRONG;
                break;
            }
        }
        if(error == WRONG)
        {
            break;
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(Board[i][c] == num)
        {
            error = WRONG;
            break;
        }
    }

    for (int j = 0; j < N; j++)
    {
        if(Board[r][j] == num)
        {
            error = WRONG;
            break;
        }
    }

    return error;
}

int Suduko_Generate_pattern(int Board[N][N],int Solved_Board[N][N])
{
    int clues_num;
    srand(time(NULL));
    do
    {
        clues_num = (rand() % (maximum_num_of_clues - minimum_num_of_clues + 1));
    } while (clues_num < minimum_num_of_clues);
    
    
    printf("clues num %d\n",clues_num);

    //initializing board array with zeros 
    for(int i = 0; i < clues_num; i++)
    {
        Board[rand() % N][rand() % N] = 0;
    } 
    return clues_num;
}



