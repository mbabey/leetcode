#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **setup_testcases(void);

int minCostClimbingStairs(int *cost, int costSize);

void free_testcases(int **testcases);

int main(void)
{
    int **testcases, **t_save;
    
    testcases = setup_testcases();
    
    t_save = testcases;
    while (*testcases)
    {
        printf("Cost: %d\n", minCostClimbingStairs(*testcases + 1, **testcases));
        testcases++;
    }
    
    free_testcases(t_save);
    return 0;
}

int minCostClimbingStairs(int *cost, int costSize)
{
    int min;
    int total_cost;
    
    total_cost = 0;
    
    for (int step = 0; step < costSize - 1;)
    {
        min = (*(cost + step) < *(cost + step + 1)) ? *(cost + step) : *(cost + step + 1);
        if (min == *(cost + step))
        {
            step += 1;
        } else
        {
            step += 2;
        }
        total_cost += min;
    }
    
    return total_cost;
}

int **setup_testcases(void)
{
    const int NUM_CASES = 2;
    
    int **testcases;
    int *cost1, *cost2;
    
    testcases = malloc(sizeof(int *) * (NUM_CASES + 1));
    
    cost1 = malloc(sizeof(int) * 4);
    cost2 = malloc(sizeof(int) * 11);
    
    // Size is stored in the first position.
    int cost1_stack[] = {3, 10, 15, 20};
    int cost2_stack[] = {10, 1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    
    memcpy(cost1, cost1_stack, sizeof(int) * 4);
    memcpy(cost2, cost2_stack, sizeof(int) * 11);
    
    *testcases = cost1;
    *(testcases + 1) = cost2;
    *(testcases + NUM_CASES) = NULL;
 
    return testcases;
}

void free_testcases(int **testcases)
{
    int **t_save = testcases;
    while (*testcases)
    {
        free(*testcases);
        testcases++;
    }
    free(t_save);
}
