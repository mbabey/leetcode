#include <iostream>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int size = static_cast<int>(nums.size());
        if (size < 2)
        {
            return 0;
        }
        
        // Sort the array
        sort(nums.begin(), nums.end(), [](int a, int b)
        {
            return (a < b);
        });
        
        int pairs{0}, start{0}, n;
        
        for (int i{1}; i < size; ++i)
        {
            while (i < size && nums[i] == nums[i - 1]) ++i;
            n     = i - start;
            pairs += n * (n - 1) / 2;
            start = i;
        }
        
        return pairs;
    }
};

int main()
{
    Solution s;
    
    vector<int> nums1{1, 2, 3, 1, 1, 3}; // 4 pairs
    vector<int> nums2{1, 1, 1, 1}; // 6 pairs
    vector<int> nums3{1, 2, 3}; // 0 pairs
    vector<int> nums4{1, 2, 3, 4, 1, 2, 3, 4};
    
    cout << "Num pairs: " << s.numIdenticalPairs(nums1) << endl;
    cout << "Num pairs: " << s.numIdenticalPairs(nums2) << endl;
    cout << "Num pairs: " << s.numIdenticalPairs(nums3) << endl;
    cout << "Num pairs: " << s.numIdenticalPairs(nums4) << endl;
    
    return EXIT_SUCCESS;
}
