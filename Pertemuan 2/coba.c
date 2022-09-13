#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int row = 3, col = 4, i, j, count;
 
    int (*arr)[row][col] = malloc(sizeof *arr);
     
    count = 0;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
           scanf("Masukkan nilai %d ", &(*arr)[i][j]);
        }
    }
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            printf("%d ", (*arr)[i][j]);
 
    free(arr);
     
    return 0;
}