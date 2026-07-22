/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void createMapping(TreeNode* root,map<TreeNode*,TreeNode*> &nodeToParent){
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty()){
            TreeNode* frontNode=q.front();
            q.pop();
            if(frontNode->left){
                q.push(frontNode->left);
                nodeToParent[frontNode->left]=frontNode;
            }
            if(frontNode->right){
                q.push(frontNode->right);
                nodeToParent[frontNode->right]=frontNode;
            }
        }
    }

    vector<int> solve(TreeNode* root,map<TreeNode*,TreeNode*> &nodeToParent,int k){
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,bool> visited;
        visited[root]=true;
        int distance=0;
        while(!q.empty()){
            if(distance++==k) break;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                if(frontNode->left && !visited[frontNode->left]){
                    q.push(frontNode->left);
                    visited[frontNode->left]=true;
                }
                if(frontNode->right && !visited[frontNode->right]){
                    q.push(frontNode->right);
                    visited[frontNode->right]=true;
                }
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                    q.push(nodeToParent[frontNode]);
                    visited[nodeToParent[frontNode]]=true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* Front=q.front();
            q.pop();
            ans.push_back(Front->val);
        }
        return ans;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> nodeToParent;
        createMapping(root,nodeToParent);
        vector<int> ans=solve(target,nodeToParent,k);
        return ans;
    }
};