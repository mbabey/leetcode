#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Test cases.
//    {{'6', '.', '.', '.', '.', '.', '8', '.', '3'},{'.', '4', '.', '7', '.', '.', '.', '.', '.'},{'.', '.', '.', '.', '.', '.', '.', '.', '.'},{'.', '.', '.', '5', '.', '4', '.', '7', '.'},{'3', '.', '.', '2', '.', '.', '.', '.', '.'},{'1', '.', '6', '.', '.', '.', '.', '.', '.'},{'.', '2', '.', '.', '.', '.', '.', '5', '.'},{'.', '.', '.', '.', '8', '.', '6', '.', '.'},{'.', '.', '.', '.', '1', '.', '.', '.', '.'}}
//    {{'.', '.', '5', '.', '.', '.', '9', '8', '7'},{'.', '4', '.', '.', '5', '.', '.', '.', '1'},{'.', '.', '7', '.', '.', '.', '.', '.', '.'},{'2', '.', '.', '.', '4', '8', '.', '.', '.'},{'.', '9', '.', '1', '.', '.', '.', '.', '.'},{'6', '.', '.', '2', '.', '.', '.', '.', '.'},{'3', '.', '.', '6', '.', '.', '2', '.', '.'},{'.', '.', '.', '.', '.', '9', '.', '7', '.'},{'.', '.', '.', '.', '.', '.', '5', '.', '.'}}
//    {{'.', '.', '.', '.', '.', '.', '.', '7', '1'},{'.', '2', '.', '8', '.', '.', '.', '.', '.'},{'.', '.', '.', '4', '.', '3', '.', '.', '.'},{'7', '.', '.', '.', '6', '.', '.', '5', '.'},{'.', '.', '.', '2', '.', '.', '3', '.', '.'},{'9', '.', '.', '.', '.', '.', '.', '.', '.'},{'6', '.', '.', '.', '7', '.', '.', '.', '.'},{'.', '8', '.', '.', '.', '.', '4', '.', '.'},{'.', '.', '.', '.', '5', '.', '.', '.', '.'}}
//    {{'.', '4', '7', '.', '8', '.', '.', '.', '1'},{'.', '.', '.', '.', '.', '.', '.', '.', '.'},{'.', '.', '.', '6', '.', '.', '7', '.', '.'},{'6', '.', '.', '.', '.', '3', '5', '7', '.'},{'.', '.', '.', '.', '.', '5', '.', '.', '.'},{'.', '1', '.', '.', '6', '.', '.', '.', '.'},{'2', '8', '.', '.', '4', '.', '.', '.', '.'},{'.', '9', '.', '1', '.', '.', '.', '4', '.'},{'.', '.', '.', '.', '2', '.', '6', '9', '.'}}
//    {{'.', '2', '.', '.', '.', '.', '.', '.', '.'},{'3', '.', '5', '.', '6', '2', '.', '.', '9'},{'.', '6', '8', '.', '.', '.', '3', '.', '.'},{'.', '5', '.', '.', '.', '.', '.', '.', '.'},{'.', '.', '.', '6', '4', '.', '8', '.', '2'},{'.', '.', '4', '7', '.', '.', '9', '.', '.'},{'.', '.', '3', '.', '.', '.', '.', '.', '1'},{'.', '.', '.', '.', '.', '6', '.', '.', '.'},{'1', '7', '.', '4', '3', '.', '.', '.', '.'}}
//    {{'1', '.', '.', '.', '.', '6', '.', '8', '.'},{'.', '6', '4', '.', '.', '.', '.', '.', '.'},{'.', '.', '.', '.', '4', '.', '.', '.', '7'},{'.', '.', '.', '.', '9', '.', '6', '.', '.'},{'.', '7', '.', '4', '.', '.', '5', '.', '.'},{'5', '.', '.', '.', '7', '.', '1', '.', '.'},{'.', '5', '.', '.', '.', '.', '3', '2', '.'},{'3', '.', '.', '.', '.', '8', '.', '.', '.'},{'4', '.', '.', '.', '.', '.', '.', '.', '.'}}
//    {{".", ".", ".", "8", ".", ".", ".", ".", "9"},{'.', '8', '7', '3', '.', '.', '.', '4', '.'},{'6', '.', '.', '7', '.', '.', '.', '.', '.'},{'.', '.', '8', '5', '.', '.', '9', '7', '.'},{'.', '.', '.', '.', '.', '.', '.', '.', '.'},{'.', '4', '3', '.', '.', '7', '5', '.', '.'},{'.', '.', '.', '.', '.', '3', '.', '.', '.'},{'.', '3', '.', '.', '.', '1', '4', '5', '.'},{'4', '.', '.', '.', '.', '2', '.', '.', '1'}}
//    {{".", "4", ".", "5", ".", ".", ".", ".", "."},{'8', '.', '.', '.', '9', '.', '.', '3', '.'},{'.', '7', '6', '.', '2', '.', '.', '.', '.'},{'.', '1', '4', '6', '.', '.', '.', '.', '.'},{'.', '.', '.', '.', '.', '9', '.', '.', '7'},{'.', '.', '.', '.', '.', '3', '6', '.', '.'},{'.', '.', '1', '.', '.', '4', '.', '5', '.'},{'.', '6', '.', '.', '.', '.', '.', '.', '3'},{'.', '.', '7', '1', '.', '.', '2', '.', '.'}}

/**
 * Dimension of the grid.
 */
#define BOARD_SIZE 9

/**
 * Maximum value for a cell
 */
#define MAX 9

/**
 * Solve a sudoku puzzle.
 * @param board the board to solve
 * @param boardSize the size of the board to solve
 * @param boardColSize the size of the columns in the board to solve
 */
void solveSudoku(char **board, int boardSize, int *boardColSize);

/**
 * Solve the sudoku puzzle.
 * @param board the board on which to solve
 * @param dst_board the original board in which to store the solution
 * @param boardSize the size of the board
 */
char **solve(char **board, int row, int col, char **dst_board, int boardSize);

int reject(char **board, int row, int col, int boardSize);

int accept(char **board, int boardSize);

int first(char t_board[9][9], int *col, int *row, char **board, int boardSize);

int next(char board[9][9], int *row, int *col, int boardSize);

char **store_solution(char **board, char **dst_board, int boardSize);

int main(void)
{
    char board_static[9][9] = {
            {'2', '6', '.', '.', '7', '.', '.', '.', '.'},
            {'.', '.', '9', '6', '.', '2', '.', '1', '.'},
            {'4', '.', '.', '3', '.', '.', '.', '.', '.'},
            {'.', '.', '3', '.', '.', '.', '.', '.', '8'},
            {'8', '.', '7', '9', '.', '4', '5', '.', '2'},
            {'9', '.', '.', '.', '.', '.', '7', '.', '.'},
            {'.', '.', '.', '.', '.', '7', '.', '.', '5'},
            {'.', '4', '.', '2', '.', '6', '1', '.', '.'},
            {'.', '.', '.', '.', '3', '.', '.', '8', '6'}};
    
    
    int      boardSize = BOARD_SIZE;
    char     **board   = (char **) malloc(sizeof(char *) * boardSize);
    for (int i         = 0; i < boardSize; ++i)
    {
        *(board + i) = (char *) malloc(boardSize);
        memcpy(*(board + i), board_static[i], boardSize);
    }
    
    solveSudoku(board, boardSize, &boardSize);

//    int arr[]    = {0, 1, 2, 3};
//    int arr_size = 4;
//    int iter     = 0;
//    int *ans;
//
//    ans = test_function(arr, NULL, arr_size, &iter);
    
    return 0;
}

void solveSudoku(char **board, int boardSize, int *boardColSize)
{
    // Solution 2: using backtracking with original grid
    
    
    
    // Solution 1: Using struct and separating into subgrids
//    struct board *board_d;
//
//    // 1: Set up the data structures.
//    board_d = create_board(board, boardSize);
//
//    // 2: Get the solution.
//    solve(board_d, &board, boardSize);
//
//    // 3: Free memory.
//    free_board(board_d);
}

int reject(char **board, int row, int col, int boardSize)
{
    char c;
    
    c = *(*(board + row) + col);
    
    for (int i = 0; i < boardSize; ++i)
    {
        // Check the row for the same number. Check the col for the same number.
        if (c == *(*(board + row) + i) || c == *(*(board + i) + col))
        {
            return 1;
        }
    }
    
    return 0;
}

int accept(char **board, int boardSize)
{
    // Check that the board contains no '.'
    for (int r = 0; r < boardSize; ++r)
    {
        for (int c = 0; c < boardSize; ++c)
        {
            if (*(*(board + r) + c) == '.')
            {
                return 0;
            }
        }
    }
    
    return 1;
}

int first(char t_board[9][9], int *col, int *row, char **board, int boardSize)
{
    // Put the board into the t_board, set row and col to the first appropriate values.
    for (int i = 0; i < boardSize; ++i)
    {
        memcpy(*(t_board + i), *(board + i), boardSize);
    }
    
    // the first appropriate values are those which correspond to the topmost leftmost '.' character.
    char c = *(*(board + *row) + *col);
    while (*row < boardSize && c != '.')
    {
        ++(*col);
        if (*col == boardSize) // Need to do the check before the assignment
        {
            *col = 0;
            ++(*row);
        }
        if (*row < boardSize)
        {
            c = *(*(board + *row) + *col);
        }
    }
    
    return (*row == boardSize) ? 0 : 1;
}

int next(char board[9][9], int *row, int *col, int boardSize)
{

}

char **solve(char **board, int row, int col, char **dst_board, int boardSize)
{
    if (reject(board, row, col, boardSize))
    {
        return NULL;
    } else if (accept(board, boardSize))
    {
        return store_solution(board, dst_board, boardSize);
    }
    
    int  cont;
    int  t_row;
    int  t_col;
    char t_board[BOARD_SIZE][BOARD_SIZE];
    
    t_row = row; // Start where it left off.
    t_col = col;
    
    cont = first(t_board, &t_col, &t_row, board, boardSize);
    while (cont)
    {
        if (solve((char **) t_board, t_row, t_col, dst_board, boardSize))
        {
            return dst_board;
        }
        cont = next(t_board, &t_row, &t_col, boardSize);
    }
    return NULL;
}

char **store_solution(char **board, char **dst_board, int boardSize)
{
    
    return dst_board;
}
