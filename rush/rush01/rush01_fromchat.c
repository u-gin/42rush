#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

int colUp[N], colDown[N], rowLeft[N], rowRight[N];
int grid[N][N];

// Function to parse the input constraints
void parse_input(char *input)
{
    sscanf(input, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
           &colUp[0], &colUp[1], &colUp[2], &colUp[3],
           &colDown[0], &colDown[1], &colDown[2], &colDown[3],
           &rowLeft[0], &rowLeft[1], &rowLeft[2], &rowLeft[3],
           &rowRight[0], &rowRight[1], &rowRight[2], &rowRight[3]);
}

// Function to check if a value can be placed at grid[row][col]
bool is_valid(int row, int col, int value)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == value || grid[i][col] == value)
            return false;
    }
    return true;
}

// Function to count the visible boxes from left/right or top/bottom
int count_visible(int *line, int *view)
{
    int max_height = 0, count = 0;
    for (int i = 0; i < N; i++)
    {
        if (line[i] > max_height)
        {
            max_height = line[i];
            count++;
        }
    }
    return count == *view;
}

// Function to check if the current grid configuration is valid
bool is_grid_valid()
{
    for (int i = 0; i < N; i++)
    {
        int row[N], col[N];
        for (int j = 0; j < N; j++)
        {
            row[j] = grid[i][j];
            col[j] = grid[j][i];
        }
        if (!count_visible(row, &rowLeft[i]) || !count_visible(row, &rowRight[i]))
            return false;
        if (!count_visible(col, &colUp[i]) || !count_visible(col, &colDown[i]))
            return false;
    }
    return true;
}

// Backtracking function to solve the grid
bool solve(int row, int col)
{
    if (row == N)
    {
        return is_grid_valid();
    }
    int nextRow = (col == N - 1) ? row + 1 : row;
    int nextCol = (col == N - 1) ? 0 : col + 1;

    for (int value = 1; value <= N; value++)
    {
        if (is_valid(row, col, value))
        {
            grid[row][col] = value;
            if (solve(nextRow, nextCol))
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

// Main function to parse input and solve the grid
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s \"constraints\"\n", argv[0]);
        return 1;
    }

    parse_input(argv[1]);

    if (solve(0, 0))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}