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
    TreeNode* createMapping(TreeNode* root,int start,map<TreeNode*,TreeNode*> &nodeToParent){
        TreeNode* res=NULL;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty()){
            TreeNode* frontNode=q.front();
            q.pop();
            if(frontNode->val==start) res=frontNode;
            if(frontNode->left){
                nodeToParent[frontNode->left]=frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right){
                nodeToParent[frontNode->right]=frontNode;
                q.push(frontNode->right);
            }
        }
        return res;
    }
    int solve(TreeNode* root,map<TreeNode*,TreeNode*> &nodeToParent){
        int count=0;
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root]=true;
        while(!q.empty()){
            int n=q.size();
            bool flag=false;
            for(int i=0;i<n;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                if(frontNode->left && !visited[frontNode->left]){
                    q.push(frontNode->left);
                    visited[frontNode->left]=true;
                    flag=true;
                }
                if(frontNode->right && !visited[frontNode->right]){
                    q.push(frontNode->right);
                    visited[frontNode->right]=true;
                    flag=true;
                }
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                    q.push(nodeToParent[frontNode]);
                    visited[nodeToParent[frontNode]]=true;
                    flag=true;
                }
            }
            if(flag) count++;
        }
        return count;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* targetNode=createMapping(root,start,nodeToParent);
        int ans=solve(targetNode,nodeToParent);
        return ans;
    }
};