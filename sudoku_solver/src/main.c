#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
typedef struct node {
    char value;
    bool set;
    struct node *next;
} node_t;

/**
 * A 9*9 grid of linked lists. Each linked list contains potential solutions for each cell
 * in the block.
 */
struct block {
    node_t *subgrid[BOARD_SIZE];
    bool filled;
};

/**
 * A 9*9 grid of struct blocks.
 */
struct board {
    struct block grid[BOARD_SIZE];
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


int main(void)
{
    
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
    struct board* board_d;
    
    board_d = (struct board*) malloc(sizeof(struct board));
    
    for (int block_num = 0; block_num < boardSize; ++block_num)
    {
        (board_d->grid + block_num) = create_block();
    }
}

struct block *create_block(const char *values, int boardSize)
{
    struct block* block;
    bool given;
    bool prefilled;
    
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
}

node_t *create_node(char value, bool set, node_t *next)
{
    node_t *node;
    
    node = (node_t *) malloc(sizeof(node_t));
    node->value = value;
    node->set = set;
    node->next = next;
    
    return node;
}

void free_board(struct board *board)
{
    for (int i = 0; i < BOARD_SIZE; ++i) {
        free_block((board->grid + i));
    }
}

void free_block(struct block *block)
{
    for (int i = 0; i < BOARD_SIZE; ++i) {
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
