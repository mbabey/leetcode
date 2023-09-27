
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMS_SIZE 4
#define TARGET 0

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int *twoSumFast(int *nums, int numsSize, int target, int *returnSize);

int *twoSumBruteForce(int *nums, int numsSize, int target, int *returnSize);

void getSumNums(int target, int *sum_nums, int **nums_map);

void mapSumNums(const int *nums, int numsSize, int target, int **nums_map);

void *static_malloc(void *mem, size_t size);

int main(void)
{
    int *two_sum;
//    int nums[NUMS_SIZE] = {2, 7, 11, 15};
//    int nums[NUMS_SIZE] = {1, 3, 3};
//    int nums[NUMS_SIZE] = {0, 4, 3, 0};
    int nums[NUMS_SIZE] = {-3,4,3,90};
    
    int returnSize;
    
    two_sum = twoSum(nums, NUMS_SIZE, TARGET, &returnSize);
    
    printf("[%d, %d]\n", *two_sum, *(two_sum + 1));
    
    free(two_sum);
    
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
//    return twoSumBruteForce(nums, numsSize, target, returnSize);
    return twoSumFast(nums, numsSize, target, returnSize);
}

int *twoSumFast(int *nums, int numsSize, int target, int *returnSize)
{
    int *sum_nums;
    int **nums_map;
    
    *returnSize = 2;
    sum_nums = malloc(*returnSize * sizeof(int));
    nums_map = malloc((target + 1) * sizeof(int *));
    memset(nums_map, 0, (target + 1) * sizeof(int *));
    
    mapSumNums(nums, numsSize, target, nums_map);
    
    getSumNums(target, sum_nums, nums_map);
    
    for (int i = 0; i <= target; ++i)
    {
        free(*(nums_map + i));
    }
    free(nums_map);
    
    return sum_nums;
}

void mapSumNums(const int *nums, int numsSize, int target, int **nums_map)
{
    // Create map for values. Store two values at key target / 2.
    for (int value = 0, key; value < numsSize; ++value)
    {
        key = *(nums + value);
        if (key <= target)
        {
            if (!(target & 1) && key == target / 2) // Key is half the even target; may need to store two values here.
            {
                *(nums_map + key) = static_malloc(*(nums_map + key), 2 * sizeof(int));
                **(nums_map + key) = value;
                *(*(nums_map + key) + 1) = value;
            } else
            {
                *(nums_map + key) = static_malloc(*(nums_map + key), sizeof(int));
                **(nums_map + key) = value;
            }
        }
    }
}

void getSumNums(int target, int *sum_nums, int **nums_map)
{
    // Get the two numbers adding up to the target from the map.
    for (int i = 0; i <= target / 2; ++i)
    {
        if (!(target & 1) && i == target / 2) // If half the even target, then the nums are the same.
        {
            *sum_nums       = **(nums_map + i);
            *(sum_nums + 1) = *(*(nums_map + i) + 1);
            break;
        }
        if (*(nums_map + i) && *(nums_map + target - i))
        {
            *sum_nums       = **(nums_map + i);
            *(sum_nums + 1) = **(nums_map + target - i);
            break;
        }
    }
}

void *static_malloc(void *mem, size_t size)
{
    if (!mem) // If already allocated, do not allocate again.
    {
        mem = malloc(size);
    }
    return mem;
}

int *twoSumBruteForce(int *nums, int numsSize, int target, int *returnSize)
{
    int *sum_nums;
    
    *returnSize = 2;
    sum_nums = malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < numsSize - 1; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (*(nums + j) + *(nums + i) == target)
            {
                *sum_nums       = i;
                *(sum_nums + 1) = j;
                return sum_nums;
            }
        }
    }
    
    return sum_nums;
}
