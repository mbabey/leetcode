#include <iostream>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
private:
    void findModeHelp(TreeNode *root, unordered_map<int, int> &map)
    {
        if (root == nullptr)
        {
            return;
        }
        findModeHelp(root->left, map);
        findModeHelp(root->right, map);
        
        if (map.contains(root->val))
        {
            ++map[root->val];
        } else
        {
            map.insert(pair<int, int>(root->val, 1));
        }
    }

public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        
        unordered_map<int, int> map;
        vector<pair<int, int>> vals;
        vector<int> ans;
        findModeHelp(root, map);
        
        for (auto &it : map)
        {
            vals.emplace_back(it);
        }
        
        sort(vals.begin(), vals.end(), [](auto a, auto b) -> bool {
            return a.second > b.second;
        });
        
        int max{vals[0].second};
        for (int i{0}; i < vals.size() && vals[i].second == max; ++i)
        {
            ans.push_back(vals[i].first);
        }
        
        return ans;
    }
};

string arr_to_string(vector<int> arr)
{
    stringstream ss;
    ss << "[";
    for (int &i:arr)
    {
        ss << " " << i << " ";
    }
    ss << "]";
    return ss.str();
}

int main()
{
    Solution s;
    
    TreeNode bottom1{2};
    TreeNode mid1{2, &bottom1, nullptr};
    TreeNode root1{1, nullptr, &mid1};
    
    TreeNode root2{};
    
    TreeNode nineleaf1{9};
    TreeNode nineleaf2{9};
    TreeNode nineleaf3{9};
    TreeNode nineroot{9, &nineleaf1, &nineleaf2};
    TreeNode tenroot1{10, &nineroot, &nineleaf3};
    TreeNode tenleaf{10};
    TreeNode tenroot2{10, nullptr, &tenleaf};
    TreeNode root3{10, &tenroot1, &tenroot2};
    
    
    cout << arr_to_string(s.findMode(&root1)) << endl;
    cout << arr_to_string(s.findMode(&root2)) << endl;
    cout << arr_to_string(s.findMode(&root3)) << endl;
    
    return 0;
}
