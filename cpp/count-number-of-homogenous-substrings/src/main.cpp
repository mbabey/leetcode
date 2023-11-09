#include <iostream>

using namespace std;

class Solution
{
public:
    int countHomogenous(string s)
    {
        auto fr{s.begin()}, bk{s.begin()}, nd{s.end()};
        long len, count{0};
        
        while (fr != nd)
        {
            while (bk != nd && *bk == *fr) ++bk;
            len = bk - fr;
            count += (len * (len + 1)) / 2;
            fr = bk;
        }
        
        return count % 1000000007;
    }
};

int main()
{
    Solution s;
    
    cout << s.countHomogenous("abbcccaa") << endl;
    cout << s.countHomogenous("xy") << endl;
    cout << s.countHomogenous("zzzzz") << endl;
    cout << s.countHomogenous("") << endl;
    cout << s.countHomogenous("qwertyuiopasdfghjklzxcvbnm") << endl;
    
    return 0;
}
