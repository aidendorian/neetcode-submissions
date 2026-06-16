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
    bool calc(TreeNode* root, int low, int high){
        if(!root)
            return true;
        if(root->val <= low || root->val >= high)
            return false;

        return calc(root->left, low, root->val) && calc(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return calc(root, INT_MIN, INT_MAX);
    }
};
