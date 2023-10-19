#include <iostream>

using namespace std;

class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        const int           mod{1000000007};
        int                 max_pos{min(steps / 2 + 1, arrLen)};
        vector<vector<int>> dp(steps + 1, vector<int>(max_pos, 0));
        
        dp[0][0] = 1;
        
        for (int i{1}; i <= steps; ++i)
        {
            for (int j{0}; j < max_pos; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (j < max_pos - 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
                
            }
        }
        return dp[steps][0];
    }
};

int main()
{
    Solution s;
 
    int steps1 = 3, arrLen1 = 2;
    int steps2 = 2, arrLen2 = 4;
    int steps3 = 4, arrLen3 = 2;
    
    cout << s.numWays(steps1, arrLen1) << endl;
    cout << s.numWays(steps2, arrLen2) << endl;
    cout << s.numWays(steps3, arrLen3) << endl;
    
    return EXIT_SUCCESS;
}
