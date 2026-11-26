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
    void createMapping(map<int,int> &nodeToIndex,int n,vector<int> inorder){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int> preorder,vector<int> inorder,int &index,int inSt,int inEn,map<int,int> &nodeToIndex,int n){
        if(index>=n || inSt>inEn){
            return NULL;
        }
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int pos=nodeToIndex[element];
        root->left=solve(preorder,inorder,index,inSt,pos-1,nodeToIndex,n);
        root->right=solve(preorder,inorder,index,pos+1,inEn,nodeToIndex,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> nodeToIndex;
        int preorderindex=0;
        int n=inorder.size();
        createMapping(nodeToIndex,n,inorder);
        TreeNode* ans=solve(preorder,inorder,preorderindex,0,n-1,nodeToIndex,n);
        return ans;
    }
};