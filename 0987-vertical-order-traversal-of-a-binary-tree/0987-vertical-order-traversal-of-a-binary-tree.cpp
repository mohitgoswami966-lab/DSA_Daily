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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        vector<vector<int>> ans;
        while(!q.empty()){
            TreeNode* frontNode=q.front().first;
            int hd=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            nodes[hd][lvl].insert(frontNode->val);
            if(frontNode->left){
                q.push({frontNode->left,{hd-1,lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right,{hd+1,lvl+1}});
            }
        }
        for(auto i:nodes){
            vector<int> col;
            for(auto j:i.second){
                for(auto k:j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};