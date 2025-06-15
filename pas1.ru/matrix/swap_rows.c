#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10


int main() {
    int matrix[ROWS][COLS];  
    int row1, row2;
    
    srand((unsigned) time(NULL));

    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Двумерный массив:\n");
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            printf("%*d ", 3, matrix[i][j]);
        }
        printf("\n");  
    }
    printf("Какие строки поменять: ");
    scanf("%d%d", &row1, &row2);

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if (i == row1)
                printf("%*d ", 3, matrix[row2][j]);
            else if (i == row2)
                printf("%*d ", 3, matrix[row1][j]);
            else
                printf("%*d ", 3, matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
