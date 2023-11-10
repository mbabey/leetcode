#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // create map
        unordered_map<int, vector<int>> p_map;
        for (auto &pair : adjacentPairs)
        {
            p_map[pair[0]].push_back(pair[1]);
            p_map[pair[1]].push_back(pair[0]);
        }
        // get first element
        vector<int> ans(size(adjacentPairs) + 1);
        
        for (auto &it : p_map)
        {
            if (it.second.size() == 1) // terminal element has only one adjacent
            {
                ans[0] = it.first;
                ans[1] = it.second[0];
            }
        }
        
        // build array
        int curr{ans[1]}, left{ans[0]}, i{2};
        int right;
        while (i < size(ans))
        {
            right = p_map[curr][0];
            if (right == left) right = p_map[curr][1];
            ans[i++] = right;
            left = curr;
            curr = right;
        }
        
        return ans;
    }
};

void print_array(vector<int> arr)
{
    cout << "[";
    for (auto &i : arr)
    {
        cout << " " << i << " ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    
    vector<vector<int>> pairs1{{2,1},{3,4},{3,2}};
    
    print_array(s.restoreArray(pairs1));
    
    return 0;
}
