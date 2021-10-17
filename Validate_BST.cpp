/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   bool helper(TreeNode* root, long min_val, long max_val){
        
        if(root == NULL){
            return true;
        }
        
        if (root->val >= max_val || root->val <= min_val) {
            return false;
        }
        
        return helper(root->left, min_val, root->val) && helper(root->right, root->val, max_val);
        
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// Time Complexity: o(n) where n is the number of nodes of the tree.
// Space Complexity: o(1)

