#include <iostream>

using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1 || k == 1)
        {
            return 0;
        }
        int mid = 1 << (n - 2); // size = 2^(n-1), mid = 2^(n-2)
        
        // If k > mid, ans = !str[k - mid], else ans = str[k]
        if (k > mid)
        {
            return !kthGrammar(n - 1, k - mid);
        }
        return kthGrammar(n - 1, k);
    }
};

int main()
{
    Solution s;
    
    cout << s.kthGrammar(1, 1) << endl;
    cout << s.kthGrammar(2, 1) << endl;
    cout << s.kthGrammar(2, 2) << endl;
    cout << s.kthGrammar(4, 8) << endl;
    
    return 0;
}
