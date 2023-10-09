#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // If the array is less than size 1, return -1, -1
        int len{static_cast<int>(nums.size())};
        
        if (!len)
        {
            return {-1, -1};
        }
        
        int start, end;
        
        // Set start and end to the location of the number found by binary search.
        start = end = binary(nums, 0, len - 1, target);
        
        while (start > 0 && nums[start] == nums[start - 1])
        {
            start--;
        }
        while (end < len - 1 && nums[end] == nums[end + 1])
        {
            end++;
        }

        return {start, end};
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

string array_to_string(vector<int> arr);

int main()
{
    Solution s;
    
    vector<int> nums1{5, 7, 7, 8, 8, 10};
    int t1 = 8;
    vector<int> nums2{5, 7, 7, 8, 8, 10};
    int t2 = 6;
    vector<int> nums3{};
    int t3 = 0;
    vector<int> nums4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int t4 = 1;
    
    cout << array_to_string(s.searchRange(nums1, t1)) << endl;
    cout << array_to_string(s.searchRange(nums2, t2)) << endl;
    cout << array_to_string(s.searchRange(nums3, t3)) << endl;
    cout << array_to_string(s.searchRange(nums4, t4)) << endl;
    
    return EXIT_SUCCESS;
}

string array_to_string(vector<int> arr)
{
    stringstream ss;
    
    ss << "[";
    for (int &i : arr)
    {
        ss << " " << i << " ";
    }
    ss << "]";
    
    return {ss.str()};
}
