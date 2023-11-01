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
    int maxCount = 0;
    int currentCount = 0;
    int currentVal = 0;
    vector<int> modes;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        
        // Check if the current value is the same as the previous one
        if (root->val == currentVal) {
            currentCount++;
        } else {
            currentVal = root->val;
            currentCount = 1;
        }
        
        // Update maxCount and modes
        if (currentCount == maxCount) {
            modes.push_back(root->val);
        } else if (currentCount > maxCount) {
            modes.clear();
            modes.push_back(root->val);
            maxCount = currentCount;
        }
        
        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        inorder(root);
        return modes;
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
