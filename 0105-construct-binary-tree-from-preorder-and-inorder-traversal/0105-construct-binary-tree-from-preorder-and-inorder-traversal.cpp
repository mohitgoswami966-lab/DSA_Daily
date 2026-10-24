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
    void createMapping(map<int,int> &nodeToIndex,vector<int> inorder,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int> preorder,vector<int> inorder,int &index,int inStart,int inEnd,map<int,int> &nodeToIndex,int n){
        if(index>=n || inStart>inEnd){
            return NULL;
        }
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int position=nodeToIndex[element];
        root->left=solve(preorder,inorder,index,inStart,position-1,nodeToIndex,n);
        root->right=solve(preorder,inorder,index,position+1,inEnd,nodeToIndex,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        map<int,int> nodeToIndex;
        int n=inorder.size();
        createMapping(nodeToIndex,inorder,n);
        TreeNode* ans=solve(preorder,inorder,preOrderIndex,0,n-1,nodeToIndex,n);
        return ans;
    }
};