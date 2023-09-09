#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Dimension of the grid.
 */
#define GRID_SIZE 9

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
    node_t *subgrid[GRID_SIZE];
    bool filled;
};

/**
 * A 9*9 grid of struct blocks.
 */
struct board {
    struct block grid[GRID_SIZE];
};

/**
 * Solve a sudoku puzzle.
 * @param board the board to solve
 * @param boardSize the size of the board to solve
 * @param boardColSize the size of the columns in the board to solve
 */
void solveSudoku(char **board, int boardSize, int *boardColSize);

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
    // 1: Set up the data structures.
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
