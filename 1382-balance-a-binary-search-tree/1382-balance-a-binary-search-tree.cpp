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
    void solve(TreeNode* root,vector<int> &inorder){
        TreeNode* curr=root;
        while(curr){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
    TreeNode* findAns(vector<int> &inorder,int s,int e){
        if(s>e) return NULL;
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->right=findAns(inorder,mid+1,e);
        root->left=findAns(inorder,s,mid-1);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        solve(root,inorder);
        int s=0;
        int e=inorder.size()-1;
        return findAns(inorder,s,e);
    }
};