#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        if (nums.size() <= 1)
        {
            return nums;
        }
    
        size_t front{0}, back{nums.size() - 1};
        
        while (front < back) {
            if (nums[front] & 1 && !(nums[back] & 1))
            {
                nums[front] += nums[back];
                nums[back] = nums[front] - nums[back];
                nums[front] -= nums[back];
            }
            front = (nums[front] & 1) ? front : front + 1;
            back = (nums[back] & 1) ? back - 1 : back;
        }
        
        return nums;
    }
    
    vector<int> sortArrayByParityIterators(vector<int> &nums) {
        if (nums.size() <= 1)
        {
            return nums;
        }
        
        auto front{nums.begin()}, back{nums.end() - 1};
        
        while (front < back) {
            if (*front & 1 && !(*back & 1))
            {
                *front += *back;
                *back = *front - *back;
                *front -= *back;
            }
            front = (*front & 1) ? front : front + 1;
            back = (*back & 1) ? back - 1 : back;
        }
        
        return nums;
    }
    
    vector<int> sortArrayByParityOneLine(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
        { return (b & 1); });
        return nums;
    }
};

void print_vec(const vector<int>& vec);

int main(void)
{
    Solution sol;
    
    vector<int> nums1{3, 1, 2, 4};
    vector<int> nums2{0};
    vector<int> nums3{90, 5000, 69, 420};
    vector<int> nums4{0, 0, 0, 0};
    vector<int> nums5{};
    vector<int> nums6{1, 3, 5, 7, 9, 11, 13, 14, 12, 10, 8, 6, 4, 2, 0};
    vector<int> nums7{4016, 2240, 402, 1600, 2540, 4665, 545, 2756, 3533, 2737, 4073, 2701, 4820, 3016, 2938, 2225,
                      2982, 1924, 2878, 1451};
    
    print_vec(sol.sortArrayByParity(nums1));
    print_vec(sol.sortArrayByParity(nums2));
    print_vec(sol.sortArrayByParity(nums3));
    print_vec(sol.sortArrayByParity(nums4));
    print_vec(sol.sortArrayByParity(nums5));
    print_vec(sol.sortArrayByParity(nums6));
    print_vec(sol.sortArrayByParity(nums7));
    
    return EXIT_SUCCESS;
}

void print_vec(const vector<int>& vec)
{
    cout << "[ ";
    for (const int &i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}
