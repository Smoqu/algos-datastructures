#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../utils/format.h"

int pathFinder(int n)
{
    srand(time(NULL)); // Initialization, should only be called once.
    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int r = rand() % 10;
            matrix[i][j] = r;
        }
        printList(matrix[i], n, 1);
    }

    /// Testing purposes
    // int matrix[10][10] = {
    //     {8, 8, 3, 9, 8, 6, 1, 3, 5, 6},
    //     {7, 5, 9, 4, 8, 3, 6, 9, 8, 1},
    //     {3, 5, 6, 4, 2, 6, 0, 7, 4, 2},
    //     {3, 8, 5, 5, 0, 1, 3, 6, 7, 0},
    //     {8, 0, 9, 6, 2, 4, 5, 3, 1, 6},
    //     {3, 6, 6, 8, 0, 4, 6, 5, 8, 5},
    //     {6, 9, 3, 2, 8, 2, 8, 3, 5, 0},
    //     {8, 1, 1, 3, 6, 5, 0, 1, 3, 2},
    //     {9, 0, 7, 2, 7, 9, 9, 3, 2, 3},
    //     {3, 7, 7, 1, 3, 2, 9, 2, 1, 2},
    // };
    // for (int i = 0; i < n; i++)
    // {
    //     printList(matrix[i], n, 1);
    // }

    int c_row = 0;
    int c_col = 0;

    int total = matrix[c_row][c_col];

    while (c_row < n && c_col < n)
    {
        printf("Row: %d, Col: %d\t", c_row, c_col);
        printf("Total: %d\n", total);
        // If at the end of the rows, but the columns are not done, keep to the right
        if (c_row >= n - 1 && c_col < n)
        {
            c_col++;
        }
        // If at the end of the columns, but the rows are not done, keep going down
        else if (c_col >= n - 1 && c_row < n)
        {
            c_row++;
        }
        else
        {
            // If the right neighbour has a greater value than the bottom one, go right.
            if (matrix[c_row + 1][c_col] < matrix[c_row][c_col + 1])
            {
                c_col++;
            }
            // If it's the opposite, go down.
            else if (matrix[c_row + 1][c_col] > matrix[c_row][c_col + 1])
            {
                c_row++;
            }
            // If they're equal
            else
            {
                // Check if right's neighbour has a greater value than bottom's neighbour,
                // if so go right
                if (matrix[c_row + 2][c_col] < matrix[c_row][c_col + 2])
                {
                    c_col++;
                }
                // else go down
                else
                {
                    c_row++;
                }
            }
        }
        // Add the current value to the total
        total += matrix[c_row][c_col];
    }

    return total;
}

int main()
{
    int found = pathFinder(10);
    printf("Found: %d", found);
    return 0;
}