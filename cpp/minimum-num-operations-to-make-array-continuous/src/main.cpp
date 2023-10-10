#include <iostream>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int len{static_cast<int>(nums.size())};
        
        // Edge cases:
        if (len == 1)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end(), [](auto a, auto b)
        {
            return a < b;
        });
        
        vector<int> dups;
        
        dups.push_back(0);
        for (int i{1}; i < len; i++)
        {
            // Track the number of duplicates encountered in the array up to i
            if (nums[i] == nums[i - 1])
            {
                dups.push_back(dups[i - 1] + 1);
            } else
            {
                dups.push_back(dups[i - 1]);
            }
        }
        
        int max_pos;
        int solution{len - 1}; // Solution starts as the maximum number of changes for the array.
        
        for (int i{0}; i < len; i++)
        {
            // If nums[i] is the min, find the location of a max such that max - min = len - 1.
            max_pos = binary(nums, 0, len - 1, len - 1 + nums[i]);
            if (max_pos > 0)
            {
                // Set the minimum solution as the number of dups plus the number of out of range values.
                int dup_count{dups[max_pos] - dups[i]};
                int out_of_range{len - (max_pos - i + 1)};
                if (dup_count + out_of_range < solution)
                {
                    solution = dup_count + out_of_range;
                }
            }
        }
        
        // If the whole array is iterated through and no solution better than len - 1 is found (ie. no max - min = len - 1)
        // Test one more solution: if there are duplicates, they need not be replaced when switching the whole array.
        if (dups[dups.size() - 1])
        {
            solution = len - dups[dups.size() - 1];
        }
        
        return solution;
    }
    
    int binary(vector<int> &arr, int start, int end, int val)
    {
        if (start >= end)
        {
            return (arr.size() && arr[start] == val) ? start : -1;
        }
        
        int size{end - start + 1};
        int pos{(size / 2) + start};
        
        if (val > arr[pos])
        {
            return binary(arr, start + size / 2, end, val);
        }
        if (val < arr[pos])
        {
            return binary(arr, start, end - size / 2, val);
        }
        return pos;
    }
};

int main()
{
    Solution s;
    
    vector<int> nums1{4, 2, 5, 3};
    vector<int> nums2{1, 2, 3, 5, 6};
    vector<int> nums3{1, 10, 100, 1000};
    vector<int> nums4{1, 2, 3, 10, 20};
    vector<int> nums5{41, 42};
    vector<int> nums6{41, 43};
    vector<int> nums7{100, 98, 96, 94, 92, 90, 88, 86, 84, 82, 80, 78, 76, 74, 72, 70, 68, 66, 64, 62};
    vector<int> nums8{100, 97, 94, 91, 88, 85, 82, 79, 76, 73, 70, 67, 64, 61, 58, 55, 52, 49, 46, 43};
    vector<int> nums9{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10};
    
//    cout << "Test 1: " << s.minOperations(nums1) << endl;
//    cout << "Test 2: " << s.minOperations(nums2) << endl;
//    cout << "Test 3: " << s.minOperations(nums3) << endl;
    cout << "Test 4: " << s.minOperations(nums4) << endl;
//    cout << "Test 5: " << s.minOperations(nums5) << endl;
//    cout << "Test 6: " << s.minOperations(nums6) << endl;
//    cout << "Test 7: " << s.minOperations(nums7) << endl;
//    cout << "Test 8: " << s.minOperations(nums8) << endl;
//    cout << "Test 9: " << s.minOperations(nums9) << endl;
    
    return EXIT_SUCCESS;
}
