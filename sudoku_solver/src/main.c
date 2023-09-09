#include <stdio.h>
#include <stdbool.h>

typedef struct potential_number {
    int value;
    struct potential_number *next;
} p_num;

struct block {
    p_num *arr[9];
    bool filled;
};

struct board {
    struct block board[9];
};

void solveSudoku(char **board, int boardSize, int *boardColSize);

int main(void)
{
    
    return 0;
}

void solveSudoku(char **board, int boardSize, int *boardColSize)
{

}
