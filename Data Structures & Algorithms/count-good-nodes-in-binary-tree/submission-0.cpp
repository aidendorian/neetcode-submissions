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
    int calc(TreeNode* root, int c_max){
        if(!root)
            return 0;
        int good = 0;
        if(root->val >= c_max)
            good = 1;
        c_max = max(c_max, root->val);
        return good+calc(root->left, c_max)+calc(root->right, c_max);

    }
    int goodNodes(TreeNode* root) {
        return calc(root, INT_MIN);
    }
};
