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
private:
    bool solve(TreeNode* leftN,TreeNode* rightN){
        if(leftN==NULL && rightN==NULL) return true;
        if(leftN==NULL || rightN==NULL) return false;
        return (leftN->val==rightN->val) && solve(leftN->left,rightN->right) && solve(leftN->right,rightN->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return NULL;
        return solve(root->left,root->right);
    }
};