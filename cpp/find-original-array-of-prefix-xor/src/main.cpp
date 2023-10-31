#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        if (pref.empty())
        {
            return {};
        }
        
        vector<int> arr;
        arr.push_back(pref[0]);
        
        for (int i = 1; i < pref.size(); ++i)
        {
            arr.push_back(abs(pref[i] ^ pref[i - 1]));
        }
        
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
    
    vector<int> pref1{5,2,0,3,1};
    
    cout << arr_to_string(s.findArray(pref1)) << endl;
    
    return 0;
}
