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
 * Bounds for the rows.
 */
#define TOP_ROW_LOWER 0
#define TOP_ROW_UPPER 2
#define MID_ROW_LOWER 3
#define MID_ROW_UPPER 5
#define BOT_ROW_LOWER 6
#define BOT_ROW_UPPER 8

/**
 * A single cell in the grid. Contains a value, whether the cell is set (i.e. locked in), and a pointer to
 * the next potential value for the cell. If set is true, then next must be NULL.
 */
typedef struct node
{
    char        value;
    bool set;
    struct node *next;
} node_t;

/**
 * A 9*9 grid of linked lists. Each linked list contains potential solutions for each cell
 * in the block.
 */
struct block
{
    node_t *subgrid[BOARD_SIZE];
    bool filled;
};

/**
 * A 9*9 grid of struct blocks.
 */
struct board
{
    struct block *grid[BOARD_SIZE];
};

/**
 * Solve a sudoku puzzle.
 * @param board the board to solve
 * @param boardSize the size of the board to solve
 * @param boardColSize the size of the columns in the board to solve
 */
void solveSudoku(char **board, int boardSize, int *boardColSize);

/**
 * Transform the input 2D array into a board data structure.
 * @param board the 2D array
 * @param boardSize the size of the board array
 * @return a board data structure
 */
struct board *create_board(char **board, int boardSize);

/**
 * Create a block containing the values passed.
 * @param values an array of characters to be stored in the block
 * @param boardSize the size of the block
 * @return a block data structure
 */
struct block *create_block(const char *values, int boardSize);

/**
 * Allocate a new node_t with a value, a set status, and a next node_t.
 * @param value the value the node_t will hold. Can be a number 0-9 or "."
 * @param set the set status of the node_t
 * @param next the next node_t
 * @return the new node_t
 */
node_t *create_node(char value, bool set, node_t *next);

/**
 * Free the memory for a struct board.
 * @param board the struct board to free
 */
void free_board(struct board *board);

/**
 * Free the memory for a struct block.
 * @param block the struct block to free
 */
void free_block(struct block *block);

/**
 * Free a linked list of node_ts.
 * @param head the head of the node_t list
 */
void free_list(node_t *head);


void get_values_for_block(char **values, char **board, int block_num);

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
    char     **board   = (char **) malloc(sizeof(char *) * BOARD_SIZE);
    for (int i         = 0; i < boardSize; ++i)
    {
        *(board + i) = (char *) malloc(boardSize);
        memcpy(*(board + i), board_static[i], boardSize);
    }
    
    solveSudoku(board, boardSize, &boardSize);
    
    return 0;
}

void solveSudoku(char **board, int boardSize, int *boardColSize)
{
    struct board *board_d;
    
    // 1: Set up the data structures.
    board_d = create_board(board, boardSize);
    
    // Free memory.
    free_board(board_d);
}

struct board *create_board(char **board, int boardSize)
{
    struct board *board_d;
    char         *values;
    
    values  = (char *) malloc(boardSize);
    board_d = (struct board *) malloc(sizeof(struct board));
    
    for (int block_num = 0; block_num < boardSize; ++block_num)
    {
        get_values_for_block(&values, board, block_num);
        
        *(board_d->grid + block_num) = create_block(values, boardSize);
    }
    
    free(values);
    
    return board_d;
}

void get_values_for_block(char **values, char **board, int block_num)
{
    int val_index;
    int col_bound;
    int row_bound;
    
    val_index = 0;
    row_bound = ((block_num / 3) + 1) * 3;
    col_bound = ((block_num % 3) + 1) * 3;
    for (int row = row_bound - 3; row < row_bound; ++row)
    {
        for (int col = col_bound - 3; col < col_bound; ++col)
        {
            *(*values + val_index) = *(*(board + row) + col);
            ++val_index;
        }
    }
}

struct block *create_block(const char *values, int boardSize)
{
    struct block *block;
    bool         given;
    bool         prefilled;
    
    block = (struct block *) malloc(sizeof(struct block));
    
    prefilled = true;
    for (int cell_num = 0; cell_num < boardSize; ++cell_num)
    {
        given = (*(values + cell_num) == '.') ? false : true;
        *(block->subgrid + cell_num) = create_node(*(values + cell_num), given, NULL);
        if (prefilled && !given)
        {
            prefilled = false;
        }
    }
    block->filled = prefilled;
    
    return block;
}

node_t *create_node(char value, bool set, node_t *next)
{
    node_t *node;
    
    node = (node_t *) malloc(sizeof(node_t));
    node->value = value;
    node->set   = set;
    node->next  = next;
    
    return node;
}

void free_board(struct board *board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        free_block(*(board->grid + i));
    }
}

void free_block(struct block *block)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        free_list(*(block->subgrid + i));
    }
}

void free_list(node_t *head)
{
    if (head == NULL)
    {
        return;
    }
    
    free_list(head->next);
    free(head);
}
