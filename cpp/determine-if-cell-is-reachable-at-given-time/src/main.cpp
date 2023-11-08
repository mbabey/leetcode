#include <iostream>

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (t == 1 && sx == fx && sy == fy) return false;
        return (max(abs(fx - sx), abs(fy - sy)) <= t);
    }
};

void print_bool(bool b)
{
    cout << ((b) ? "True" : "False") << endl;
}

int main()
{
    Solution s;
    
    print_bool(s.isReachableAtTime(2, 4, 7, 7, 6)); // t
    print_bool(s.isReachableAtTime(3, 1, 7, 3, 3)); // f
    print_bool(s.isReachableAtTime(1, 1, 1, 1, 3)); // t
    
    return 0;
}
