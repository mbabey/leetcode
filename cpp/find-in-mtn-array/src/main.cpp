#include <iostream>

using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray
{
private:
    vector<int> mtn;

public:
    explicit MountainArray(vector<int> arr)
    {
        mtn = std::move(arr);
    }
    
    int get(int index)
    {
        return mtn[index];
    }
    
    int length()
    {
        return static_cast<int>(mtn.size());
    }
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int peak_index;
        int target_index;
    
        peak_index = peak(mountainArr);
        target_index = binary(mountainArr, 0, peak_index, target);
        if (target_index == -1)
        {
            target_index = reverse_binary(mountainArr, peak_index, mountainArr.length() - 1, target);
        }
        
        return target_index;
    }
    
    
    int peak(MountainArray &mtn)
    {
        int low{0}, mid, high{mtn.length() - 1};
        int mid_val, mid_val_up;
        
        while (high > low)
        {
            mid = low + (high - low) / 2;
            mid_val = mtn.get(mid);
            mid_val_up = mtn.get(mid + 1);
            if (mid_val >= mid_val_up)
            {
                high = mid;
            } else
            {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int binary(MountainArray &mtn, int start, int end, int target)
    {
        if (mtn.length() == 0)
        {
            return -1;
        }
        if (start >= end)
        {
            return (mtn.get(start) == target) ? start : -1;
        }
        
        int size{end - start + 1};
        int pos{start + size / 2};
        int val = mtn.get(pos);
        
        if (target < val)
        {
            return binary(mtn, start, end - size / 2, target);
        }
        if (target > val)
        {
            return binary(mtn, start + size / 2, end, target);
        }
        return pos; // if found.
    }
    
    int reverse_binary(MountainArray &mtn, int start, int end, int target)
    {
        if (mtn.length() == 0)
        {
            return -1;
        }
        if (start >= end)
        {
            return (mtn.get(start) == target) ? start : -1;
        }
        
        int size{end - start + 1};
        int pos{start + size / 2};
        int val = mtn.get(pos);
        
        if (target > val)
        {
            return reverse_binary(mtn, start, end - size / 2, target);
        }
        if (target < val)
        {
            return reverse_binary(mtn, start + size / 2, end, target);
        }
        return pos; // if found.
    }
};

int main()
{
    Solution s;
    
    MountainArray mtn1{vector<int>{1, 2, 3, 4, 5, 3, 1}};
    MountainArray mtn2{vector<int>{0, 1, 2, 4, 2, 1}};
    MountainArray mtn3{vector<int>{1, 5, 2}};
    MountainArray mtn4{vector<int>{0, 5, 3, 1}};
    
    cout << s.findInMountainArray(3, mtn1) << endl; // 2
    cout << s.findInMountainArray(3, mtn2) << endl; // -1
    cout << s.findInMountainArray(2, mtn3) << endl; // 2
    cout << s.findInMountainArray(1, mtn4) << endl; // 3
    
    return 0;
}
