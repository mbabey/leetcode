#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row;
        
        row.push_back(1);
        
        if (rowIndex == 0)
        {
            return row;
        }
        
        long val;
        for (int i{1}; i <= rowIndex / 2; ++i)
        {
            val = row[i - 1];
            val *= (rowIndex + 1 - i);
            val /= i;
            row.push_back(static_cast<int>(val));
        }
        
        for (int i{(rowIndex - 1) / 2}; i >= 0; i--)
        {
            row.push_back(row[i]);
        }
        
        return row;
    }
};

template<typename T>
string arr_to_string(vector<T> arr);

int main()
{
    Solution s;
    
    cout << arr_to_string(s.getRow(0)) << endl;
    cout << arr_to_string(s.getRow(1)) << endl;
    cout << arr_to_string(s.getRow(2)) << endl;
    cout << arr_to_string(s.getRow(3)) << endl;
    cout << arr_to_string(s.getRow(4)) << endl;
    cout << arr_to_string(s.getRow(5)) << endl;
    cout << arr_to_string(s.getRow(6)) << endl;
    cout << arr_to_string(s.getRow(7)) << endl;
    cout << arr_to_string(s.getRow(8)) << endl;
    cout << arr_to_string(s.getRow(9)) << endl;
    cout << arr_to_string(s.getRow(10)) << endl;
    cout << arr_to_string(s.getRow(11)) << endl;
    cout << arr_to_string(s.getRow(12)) << endl;
    cout << arr_to_string(s.getRow(13)) << endl;
    cout << arr_to_string(s.getRow(14)) << endl;
    cout << arr_to_string(s.getRow(15)) << endl;
    cout << arr_to_string(s.getRow(16)) << endl;
    cout << arr_to_string(s.getRow(17)) << endl;
    cout << arr_to_string(s.getRow(18)) << endl;
    cout << arr_to_string(s.getRow(19)) << endl;
    cout << arr_to_string(s.getRow(20)) << endl;
    cout << arr_to_string(s.getRow(21)) << endl;
    cout << arr_to_string(s.getRow(22)) << endl;
    cout << arr_to_string(s.getRow(23)) << endl;
    cout << arr_to_string(s.getRow(24)) << endl;
    cout << arr_to_string(s.getRow(25)) << endl;
    cout << arr_to_string(s.getRow(26)) << endl;
    cout << arr_to_string(s.getRow(27)) << endl;
    cout << arr_to_string(s.getRow(28)) << endl;
    cout << arr_to_string(s.getRow(29)) << endl;
    cout << arr_to_string(s.getRow(30)) << endl;
    cout << arr_to_string(s.getRow(31)) << endl;
    cout << arr_to_string(s.getRow(32)) << endl;
    cout << arr_to_string(s.getRow(33)) << endl;
    
    return EXIT_SUCCESS;
}

template<typename T>
string arr_to_string(vector<T> arr)
{
    stringstream ss;
    ss << "[";
    for (T &i : arr)
    {
        ss << " " << i << " ";
    }
    ss << "]";
    return ss.str();
}
