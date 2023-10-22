#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Start from the subarray that includes only the k element. Expand left and right using 2 pointers.
 * The farther the pointers are, the better for the score. But the minimum value can «harm» the score significantly, so it needs to be maximized.
 * Finding the minimum number of the subarray takes O(1) if you move 1 pointer 1 index at a time.
 * When you choose which pointer to move, choose the one that will «harm» the minimum value less.
 */


static int maximumScore(int *nums, int numsSize, int k)
{
    int fr, bk, max_score, temp_score, min, temp_min;
    fr = k;
    bk = k;
    max_score = *(nums + k);
    min = *(nums + k);
    
    while (fr > 0 && bk < numsSize - 1)
    {
        if (*(nums + fr - 1) < *(nums + bk + 1))
        {
            ++bk;
            temp_min = *(nums + bk);
        } else
        {
            --fr;
            temp_min = *(nums + fr);
        }
        
        if (temp_min < min) {
            min = temp_min;
        }
        temp_score = min * (bk - fr + 1);
        if (temp_score > max_score)
        {
            max_score = temp_score;
        }
    }
    
    while (fr > 0)
    {
        --fr;
        temp_min = *(nums + fr);
        if (temp_min < min) {
            min = temp_min;
        }
        temp_score = min * (bk - fr + 1);
        if (temp_score > max_score)
        {
            max_score = temp_score;
        }
    }
    
    while (bk < numsSize - 1)
    {
        ++bk;
        temp_min = *(nums + bk);
        if (temp_min < min) {
            min = temp_min;
        }
        temp_score = min * (bk - fr + 1);
        if (temp_score > max_score)
        {
            max_score = temp_score;
        }
    }
    
    return max_score;
}

int main(void)
{
    int static1[] = {1, 4, 3, 7, 4, 5};
    int *test1 = malloc(sizeof(static1));
    memcpy(test1, static1, sizeof(static1));
    
    int res1 = maximumScore(test1, sizeof(static1) / sizeof(int), 3);
    
    printf("%d\n", res1);
    
    free(test1);
    
    return 0;
}
