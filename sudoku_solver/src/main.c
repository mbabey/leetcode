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

char **store_solution(char **board, char **dst_board, int boardSize);

char **make_board(int boardSize);

int first(char **t_board, int *col, int *row, char **board, int boardSize);

void free_board(char **board, int boardSize);

int next(char **board, int row, int col, int boardSize);

void print_board(char **board, int boardSize);

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
    
    print_board(board, boardSize);
    
    return 0;
}

void print_board(char **board, int boardSize)
{
    for (int r = 0; r < boardSize; ++r)
    {
        for (int c = 0; c < boardSize; ++c)
        {
            (void) printf(" %c ", *(*(board + r) + c));
        }
        (void) printf("\n");
    }
}

void solveSudoku(char **board, int boardSize, int *boardColSize)
{
    solve(board, 0, 0, board, boardSize);
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
    char **t_board;
    char **res;
    
    t_row   = row; // Start where it left off.
    t_col   = col;
    t_board = make_board(boardSize);
    
    cont = first(t_board, &t_col, &t_row, board, boardSize);
    while (cont)
    {
        res = solve(t_board, t_row, t_col, dst_board, boardSize);
        if (res)
        {
            free_board(t_board, boardSize);
            return dst_board;
        }
        cont = next(t_board, t_row, t_col, boardSize);
    }
    
    free_board(t_board, boardSize);
    return NULL;
}

int reject(char **board, int row, int col, int boardSize)
{
    char c;
    
    c = *(*(board + row) + col);
    
    // Check the col for the same number.
    for (int i = 0; i < boardSize; ++i)
    {
        if (i != row && c == *(*(board + i) + col))
        {
            return 1;
        }
    }
    
    // Check the row for the same number.
    for (int i = 0; i < boardSize; ++i)
    {
        if (i != col && c == *(*(board + row) + i))
        {
            return 1;
        }
    }
    
    // Check the block for the same number.
    
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

char **store_solution(char **board, char **dst_board, int boardSize)
{
    for (int i = 0; i < boardSize; ++i)
    {
        memcpy(*(dst_board + i), *(board + i), boardSize);
    }
    
    return dst_board;
}

char **make_board(int boardSize)
{
    char     **board = (char **) malloc(sizeof(char *) * boardSize);
    for (int i       = 0; i < boardSize; ++i)
    {
        *(board + i) = (char *) malloc(boardSize);
    }
    return board;
}

int first(char **t_board, int *col, int *row, char **board, int boardSize)
{
    // Put the board into the t_board, set row and col to the first appropriate values.
    for (int i = 0; i < boardSize; ++i)
    {
        memcpy(*(t_board + i), *(board + i), boardSize);
    }
    
    // the first appropriate values are those which correspond to the topmost leftmost '.' character.
    char c = *(*(t_board + *row) + *col);
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
            c = *(*(t_board + *row) + *col);
        }
    }
    
    int ret_val;
    
    if (*row == boardSize)
    {
        ret_val = 0;
    } else
    {
        *(*(t_board + *row) + *col) = '1';
        ret_val = 1;
    }
    
    return ret_val;
}

void free_board(char **board, int boardSize)
{
    for (int i = 0; i < boardSize; ++i)
    {
        free(*(board + i));
    }
    free(board);
}

int next(char **board, int row, int col, int boardSize)
{
    if (*(*(board + row) + col) + (char) 1 > '9')
    {
        return 0;
    } else
    {
        ++(*(*(board + row) + col));
        return 1;
    }
}
