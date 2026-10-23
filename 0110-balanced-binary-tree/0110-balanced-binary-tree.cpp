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
    pair<bool,int> solve(TreeNode* root){
        if(root==NULL) return {true,0};
        pair<bool,int> leftNode=solve(root->left);
        pair<bool,int> rightNode=solve(root->right);
        bool first=leftNode.first;
        bool second=rightNode.first;
        bool diff=abs(leftNode.second-rightNode.second)<=1;
        pair<bool,int> ans;
        if(first && second && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        ans.second=max(leftNode.second,rightNode.second)+1;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};