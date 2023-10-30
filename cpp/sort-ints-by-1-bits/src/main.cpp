#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [](int a, int b) -> bool
        {
            size_t a_bits = __builtin_popcount(a);
            size_t b_bits = __builtin_popcount(b);
            return (a_bits == b_bits) ? a < b : a_bits < b_bits;
        });
        
        return arr;
    }
};

string arr_to_string(vector<int> arr)
{
    stringstream ss;
    
    ss << "[";
    for (int &i : arr)
    {
        ss << " " << i << " ";
    }
    ss << "]";
    return ss.str();
}

int main()
{
    Solution s;
    
    vector<int> test1{0,1,2,3,4,5,6,7,8};
    vector<int> test2{1024,512,256,128,64,32,16,8,4,2,1};
    
    cout << arr_to_string(s.sortByBits(test1)) << endl;
    cout << arr_to_string(s.sortByBits(test2)) << endl;
    
    return 0;
}
