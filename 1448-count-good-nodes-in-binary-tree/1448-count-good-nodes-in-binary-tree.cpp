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
    int solve(TreeNode* root,int maxTillNow){
        if(!root) return 0;
        int count=0;
        if(root->val>=maxTillNow) count=1;
        maxTillNow=max(maxTillNow,root->val);
        count += solve(root->left,maxTillNow);
        count += solve(root->right,maxTillNow);
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};