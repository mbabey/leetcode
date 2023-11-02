#include <iostream>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int      val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

class Solution
{
private:
    int count = 0;
    
    void getAvg(TreeNode *root, int *sum, int *size)
    {
        // Use post-order traversal to get the avgs of both left and right trees.
        if (root == nullptr)
        {
            *sum = 0;
            *size = 0;
            return;
        }
    
        int left_sum, left_size, right_sum, right_size;
        getAvg(root->left, &left_sum, &left_size);
        getAvg(root->right, &right_sum, &right_size);
    
        if (left_size == 0 && right_size == 0) // is leaf.
        {
            // Leaves' values will always equal the value of their avg (leaf->val / 1 = leaf->val).
            ++count;
            *sum  = root->val;
            *size = 1;
            return;
        }
    
        *sum = left_sum + right_sum + root->val;
        *size = left_size + right_size + 1;
        
        if ((*sum / *size) == root->val)
        {
            count++;
        }
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        int sum, size;
        getAvg(root, &sum, &size);
        int ans = count;
        count = 0;
        return ans;
    }
};

int main()
{
    Solution s;
    
    TreeNode root1{1};
    
    TreeNode root2{};
    
    TreeNode threeleaf{3};
    TreeNode bottom1{1, nullptr, &threeleaf};
    TreeNode bottom3{3, nullptr, &bottom1};
    TreeNode root3{1, nullptr, &bottom3};
    
    cout << s.averageOfSubtree(&root1) << endl;
    cout << s.averageOfSubtree(&root2) << endl;
    cout << s.averageOfSubtree(&root3) << endl;
    
    return 0;
}
