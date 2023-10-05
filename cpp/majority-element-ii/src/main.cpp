#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        size_t n{nums.size()};
        
        if (n < 3)
        {
            if (n == 2 && nums[0] == nums[1])
            {
                nums.erase(nums.begin());
            }
            return nums;
        }
        
        sort(nums.begin(), nums.end(), [](auto a, auto b)
        { return (a < b); });
        
        vector<int> ans;
        
        for (size_t i{1}, start{0}; i < n; ++i)
        {
            while (i < n && nums[i] == nums[i - 1]) ++i;
            if (i - start > n / 3)
            {
                ans.push_back(nums[i - 1]);
            }
            start = i;
        }
        
        return ans;
    }
};

void arr_to_string(vector<int> arr);

int main()
{
    Solution s;
    
    vector<int> t1{3, 2, 3};
    vector<int> t2{1};
    vector<int> t3{1, 2};
    vector<int> t4{2, 2};
    vector<int> t5{3, 1, 2, 3, 2, 3};
    vector<int> t6{2, 9, 1, 9, 4, 3, 8, 9};
    
    arr_to_string(s.majorityElement(t1));
    arr_to_string(s.majorityElement(t2));
    arr_to_string(s.majorityElement(t3));
    arr_to_string(s.majorityElement(t4));
    arr_to_string(s.majorityElement(t5));
    arr_to_string(s.majorityElement(t6));
    
    return EXIT_SUCCESS;
}

void arr_to_string(vector<int> arr)
{
    cout << "[";
    for (int i : arr)
    {
        cout << " " << i << " ";
    }
    cout << "]" << endl;
}
