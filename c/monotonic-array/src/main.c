#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMonotonic(int *nums, int numsSize);

void print_bool(bool b);

int main(void)
{
    int nums1[] = {1, 2, 2, 3};
    int nums2[] = {6, 5, 4, 4};
    int nums3[] = {1, 3, 2};
    int nums4[] = {1, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    int nums5[] = {1, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1};
    int nums6[] = {1, 3, 2, 4, 3, 5, 4, 6};
    int nums7[] = {9, 9, 9, 9, 9, 9, 3, 12, 13};
    
    print_bool(isMonotonic(nums1, sizeof(nums1) / sizeof(int)));
    print_bool(isMonotonic(nums2, sizeof(nums2) / sizeof(int)));
    print_bool(isMonotonic(nums3, sizeof(nums3) / sizeof(int)));
    print_bool(isMonotonic(nums4, sizeof(nums4) / sizeof(int)));
    print_bool(isMonotonic(nums5, sizeof(nums5) / sizeof(int)));
    print_bool(isMonotonic(nums6, sizeof(nums6) / sizeof(int)));
    print_bool(isMonotonic(nums7, sizeof(nums7) / sizeof(int)));
    
    return EXIT_SUCCESS;
}

bool isMonotonic(int *nums, int numsSize)
{
    if (numsSize < 3)
    {
        return true;
    }
    
    int is_increasing = -1;
    
    for (int i = 0; i < numsSize - 1; ++i)
    {
        if (*(nums + i) < *(nums + i + 1)) // increasing
        {
            if (is_increasing == -1)
            {
                is_increasing = 1;
            } else if (is_increasing == 0) // already decreasing
            {
                return false;
            }
        } else if (*(nums + i) > *(nums + i + 1)) // decreasing
        {
            if (is_increasing == -1)
            {
                is_increasing = 0;
            } else if (is_increasing == 1) // already increasing
            {
                return false;
            }
        }
    }
    
    return true;
}

void print_bool(bool b)
{
    (void) printf("%s\n", b ? "true" : "false");
}
