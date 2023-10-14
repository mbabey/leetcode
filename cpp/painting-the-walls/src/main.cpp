#include <iostream>

using namespace std;

class Solution
{
public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int len{static_cast<int>(cost.size())};
        
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        
        for (int i = 1; i <= len; ++i)
        {
            dp[len][i] = 1e9;
        }
        
        int do_paint, dont_paint;
        
        for (int room = len - 1; room >= 0; --room)
        {
            for (int remaining = 1; remaining <= len; ++remaining)
            {
                do_paint = cost[room] + dp[room + 1][max(remaining - 1 - time[room], 0)];
                dont_paint = dp[room + 1][remaining];
                
                dp[room][remaining] = min(do_paint, dont_paint);
            }
        }
        
        return dp[0][len];
    }
};

int main()
{
    Solution s;
    
    vector<int> cost1{1, 2, 3, 2};
    vector<int> time1{1, 2, 3, 2};
    
    vector<int> cost2{2, 3, 4, 2};
    vector<int> time2{1, 1, 1, 1};
    
    cout << s.paintWalls(cost1, time1) << endl;
    cout << s.paintWalls(cost2, time2) << endl;
    
    return 0;
}
