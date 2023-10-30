#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
private:
    int compareBits(int a, int b) // 1 if a > b; 0 if a == b; -1 if a < b
    {
        int a_bit{0}, b_bit{0};

        while (a)
        {
            if (a & 1)
            {
                ++a_bit;
            }
            a >>= 1;
        }
        while (b)
        {
            if (b & 1)
            {
                ++b_bit;
            }
            b >>= 1;
        }
        
        if (a_bit > b_bit)
        {
            return 1;
        }
        if (a_bit < b_bit)
        {
            return -1;
        }
        return 0;
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        int bits{0};
        sort(arr.begin(), arr.end(), [bits, this](int a, int b) mutable -> bool
        {
            bits = compareBits(a, b);
            if (bits > 0)
            {
                return false;
            }
            if (bits < 0)
            {
                return true;
            }
            return a < b;
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
