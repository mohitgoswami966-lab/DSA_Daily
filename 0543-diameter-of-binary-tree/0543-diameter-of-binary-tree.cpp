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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int> leftNode=solve(root->left);
        pair<int,int> rightNode=solve(root->right);
        int op1=leftNode.first;
        int op2=rightNode.first;
        int op3=leftNode.second + rightNode.second;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(leftNode.second,rightNode.second)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};