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
    int ans = 0;
    int height(TreeNode* node){
        if(!node)
            return 0;
        int l = height(node->left);
        int r = height(node->right);

        ans = max(l+r, ans);
        return 1+max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};
