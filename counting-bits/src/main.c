#include <stdio.h>
#include <stdlib.h>

int *countBits(int n, int *returnSize);

void print_array(int *arr, int size);

int main(void)
{
    int input;
    int return_size;
    int *output;
    
    input = 0;
    
    output = countBits(input, &return_size);
    
    print_array(output, return_size);
    
    free(output);
    
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize)
{
    int *arr;
    int bitwise;
    int count;
    
    arr = (int *) malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;
    
    // Iterate from 0 to n.
    for (int i = 0; i <= n; i++)
    {
        count = 0;
        bitwise = i;
    
        // Shift right and check the lowest order bit against 1 while the current value is not 0.
        while (bitwise > 0)
        {
            if (bitwise & 1)
            {
                // Increment count if bit is 1.
                count++;
            }
            // Shift right.
            bitwise >>= 1;
        }
        
        *(arr + i) = count;
    }
    
    return arr;
}

void print_array(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", *(arr + i));
    }
    printf("]\n");
}
