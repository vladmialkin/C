#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10


int main() {
    int matrix[ROWS][COLS];  
    
    int sum = 0;   
    srand((unsigned) time(NULL));

    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Двумерный массив:\n");
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            sum += matrix[i][j];
            printf("%*d ", 3, matrix[i][j]);
        }
        printf("\n");  
    }
    printf("sum: %d", sum);
    
    return 0;
}
