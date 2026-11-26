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
    void solve(TreeNode* root,vector<int> &paths,int targetSum,int &count){
        if(root==NULL) return;
        paths.push_back(root->val);
        solve(root->left,paths,targetSum,count);
        solve(root->right,paths,targetSum,count);
        int n=paths.size();
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=paths[i];
            if(sum==targetSum) count++;
        }
        paths.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> paths;
        int count=0;
        solve(root,paths,targetSum,count);
        return count;
    }
};