#include <iostream>

using namespace std;

class Solution
{
public:
    
    /**
     * Logic:
     * The maximum product of x's of an integer n split into n/x x's is when x = e.
     * 3 is the closest integer to e. 2 is the next closest. 4 is closer than 1.
     */
    int integerBreak(int n)
    {
        if (n <= 3) // Edge cases: 3 and 2
        {
            // 2 = 1 + 1 -> 1 * 1 = 1
            // 3 = 2 + 1 -> 2 * 1 = 2
            return n - 1;
        }
        
        // Break it into as many 3's as possible until we can't break it into 3's.
        // Then, if there is 1 left, add it to one of the 3's.
        int res;
        int num_threes{n / 3};
        
        if (n % 3 == 2) // eg: 3 + 3 + 3 + 2
        {
            res = static_cast<int>(pow(3, num_threes)) * 2;
        } else if (n % 3 == 1) // eg: 3 + 3 + 3 + 1 -> 3 + 3 + 4
        {
            --num_threes;
            res = static_cast<int>(pow(3, num_threes)) * 4;
        } else // eg: 3 + 3 + 3
        {
            res = static_cast<int>(pow(3, num_threes));
        }
        
        return res;
    }
};

int main()
{
    Solution s;
    
    cout << s.integerBreak(2) << endl;
    cout << s.integerBreak(10) << endl;
    cout << s.integerBreak(3) << endl;
    cout << s.integerBreak(4) << endl;
    cout << s.integerBreak(9) << endl;
    cout << s.integerBreak(17) << endl;
    
    
    return EXIT_SUCCESS;
}
