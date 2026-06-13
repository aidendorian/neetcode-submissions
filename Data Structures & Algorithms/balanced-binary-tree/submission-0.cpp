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
    bool ans = true;
    int height(TreeNode* node){
        if(!node)
            return 0;
        int l = 1+height(node->left);
        int r = 1+height(node->right);
        if(abs(l-r)>1)
            ans = false;
        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};