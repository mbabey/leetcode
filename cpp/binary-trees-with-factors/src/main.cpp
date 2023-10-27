#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        if (arr.empty())
        {
            return 0;
        }
        
        // Make a map from the sorted array
        const int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        
        for (auto num : arr)
        {
            dp.insert(pair<int, long long>(num, 1));
            double   max_i{sqrt(num)};
            for (int i = 2; i <= max_i; ++i)
            {
                if (dp.contains(i))
                {
                    long long val{dp[i]};
                    if (i == max_i)
                    {
                        dp[num] += val * val;
                    } else if (num % i == 0 && dp.contains(num / i))
                    {
                        dp[num] += 2 * val * dp[num / i];
                    }
                }
            }
        }
        
        long long       ans{0};
        for (auto &num : arr)
        {
            ans += dp[num];
        }
        
        return static_cast<int>(ans % MOD);
    }
};

int main()
{
    Solution s;
    
    vector<int> nums1{2, 4};
    vector<int> nums2{2, 4, 5, 10};
    vector<int> nums3{18, 3, 6, 2};
    vector<int> nums4{45, 42, 2, 18, 23, 1170, 12, 41, 40, 9, 47, 24, 33, 28, 10, 32, 29, 17, 46, 11, 759, 37, 6, 26,
                      21, 49, 31, 14, 19, 8, 13, 7, 27, 22, 3, 36, 34, 38, 39, 30, 43, 15, 4, 16, 35, 25, 20, 44, 5,
                      48};
    
//    cout << s.numFactoredBinaryTrees(nums1) << endl;
//    cout << s.numFactoredBinaryTrees(nums2) << endl;
//    cout << s.numFactoredBinaryTrees(nums3) << endl;
    cout << s.numFactoredBinaryTrees(nums4) << endl;
    
    return 0;
}
