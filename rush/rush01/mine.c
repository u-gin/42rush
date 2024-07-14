#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_board(int board[4][4], char *borders)
{
    printf("**************************************************\n\n");
    //top
    printf(" \t");
    for (int col = 0; col < 4; col++)
    {
        printf("%c\t", borders[col]);
    }
    printf("\n\n");

    //board
    for (int row = 0; row < 4; row++)
    {
        //left
        printf("%c\t", borders[8 + row]); 
        for (int col = 0; col < 4; col++)
        {
            printf("%d\t", board[row][col]);
        }
        //right
        printf("%c\n", borders[12 + row]); 
    }
    printf("\n");
    //bottom
    printf(" \t");
    for (int col = 4; col < 8; col++)
    {
        printf("%c\t", borders[col]);
    }
    printf("\n\n");
    printf("**************************************************\n\n");
}



void conditions(char* borders, int board[4][4]){
    for (int r = 0; r < 4; r++)
    {
        
        if (borders[8 + r] == '4')
        {
            board[r][0] = 1;
            board[r][1] = 2;
            board[r][2] = 3;
            board[r][3] = 4;
        }
        if (borders[12 + r] == '4')
        {
            board[r][0] = 4;
            board[r][1] = 3;
            board[r][2] = 2;
            board[r][3] = 1;
        }
    }
    for (int c = 0; c < 4; c++)
    {
        
        if (borders[c] == '4')
        {
            board[0][c] = 1;
            board[1][c] = 2;
            board[2][c] = 3;
            board[3][c] = 4;
        }
        if (borders[4 + c] == '4')
        {
            board[0][c] = 4;
            board[1][c] = 3;
            board[2][c] = 2;
            board[3][c] = 1;
        }
    }

    //chek opposites
    for (int r = 0; r < 4; r++){
        if (borders[8 + r] == '1' && borders[12 + r] == '2')
        {
            board[r][0] = 4;
            board[r][3] = 3;
        }

        if (borders[8 + r] == '2' && borders[12 + r] == '1')
        {
            board[r][0] = 3;
            board[r][3] = 4;
        }
    }

    for (int c = 0; c < 4; c++)
    {
        if (borders[c] == '1' && borders[4 + c] == '2')
        {
            board[0][c] = 4;
            board[3][c] = 3;
        }

        if (borders[c] == '2' && borders[4 + c] == '1')
        {
            board[0][c] = 3;
            board[3][c] = 4;
        }
    }

    //check oposite diagonals
    if (board[0][0] == 4 && board[3][3] == 4)
    {
        board[1][1] = 4;
        board[2][2] = 4;
    }

    if (board[0][3] == 4 && board[3][0] == 4)
    {
        board[1][2] = 4;
        board[2][1] = 4;
    }
}

int** malloc_arr(int board[4][4])
{
    int **new_board = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        new_board[i] = (int *)malloc(4 * sizeof(int));
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            new_board[i][j] = board[i][j];
        }
    }

    return new_board;
}


// check rows flow
void  check_rows(char* borders, int board[4][4]){



}


// check columns flow
/* void check_columns(char* borders, int board[4][4]){
    int checker[4];
    for (int c = 0; c < 4; c++){
        int line_number = borders[c];
        int max = 0;

        if (board[c][0] > max)
        {
            max = board[c][0];

            checker[c]
 
            return 0;
        }
        else{
            if ()
            {
                
            }   
        }
    }
}  */

int main(int argc, char **argv){

    if (argc != 2)
    {
        return (1);
    }

    char *input = argv[1];
    if (strlen(input) != 31)
    { 
        printf("Error: Enter each number followed by a space)\n");
        return 1;
    }

    char borders[16];
    for (int i = 0; i < 16; i++)
    {
        
        
        if (input[i*2] <=0 && input[i*2] > 4)
        {
            printf("Error: Entry shoould be from numbers 1 to 4\n");
            return 1;
        }
        
        borders[i] = input[i * 2];
    }

    int board[4][4] = {0};

    conditions(borders, board);
    print_board(board, borders);

    return (0);
}