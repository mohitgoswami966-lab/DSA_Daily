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
    TreeNode* createMapping(map<TreeNode*,TreeNode*> &nodeToParent,TreeNode* root,int start){
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
                q.push(frontNode->left);
                nodeToParent[frontNode->left]=frontNode;
            }
            if(frontNode->right){
                q.push(frontNode->right);
                nodeToParent[frontNode->right]=frontNode;
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
                    flag=true;
                    visited[frontNode->left]=true;
                    q.push(frontNode->left);
                }
                if(frontNode->right && !visited[frontNode->right]){
                    flag=true;
                    visited[frontNode->right]=true;
                    q.push(frontNode->right);
                }
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                    flag=true;
                    visited[nodeToParent[frontNode]]=true;
                    q.push(nodeToParent[frontNode]);
                }
            }
            if(flag) count++;
        }
        return count;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* targetNode=createMapping(nodeToParent,root,start);
        int ans=solve(targetNode,nodeToParent);
        return ans;
    }
};