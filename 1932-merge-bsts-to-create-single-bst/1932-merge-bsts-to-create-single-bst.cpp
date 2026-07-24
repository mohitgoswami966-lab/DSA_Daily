class Solution {
private:
    bool dfs(TreeNode* node, long low, long high,unordered_map<int, TreeNode*>& mp) {
        if (!node) return true;
        if (node->val <= low || node->val >= high) return false;
        if (!node->left && !node->right && mp.count(node->val)) {
            TreeNode* t = mp[node->val];
            node->left = t->left;
            node->right = t->right;
            mp.erase(node->val);
        }
        return dfs(node->left, low, node->val, mp) && dfs(node->right, node->val, high, mp);
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> leaf;
        for (auto t : trees) mp[t->val] = t;
        for (auto t : trees) {
            if (t->left) leaf[t->left->val]++;
            if (t->right) leaf[t->right->val]++;
        }
        TreeNode* root = nullptr;
        for (auto t : trees) {
            if (!leaf.count(t->val)) {
                root = t;
                break;
            }
        }
        if (!root) return nullptr;
        mp.erase(root->val);
        if (!dfs(root, LONG_MIN, LONG_MAX, mp)) return nullptr;
        return mp.empty() ? root : nullptr;
    }
};