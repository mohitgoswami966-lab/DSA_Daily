class Solution {
public:
    struct Node {
        char lc, rc;
        int pre, suf, mx, len;

        Node() {
            lc = rc = '#';
            pre = suf = mx = len = 0;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pre = a.pre;
        res.suf = b.suf;
        res.mx = max(a.mx, b.mx);

        // Prefix can extend into right segment
        if (a.pre == a.len && a.rc == b.lc)
            res.pre = a.len + b.pre;

        // Suffix can extend into left segment
        if (b.suf == b.len && a.rc == b.lc)
            res.suf = b.len + a.suf;

        // Middle combination
        if (a.rc == b.lc)
            res.mx = max(res.mx, a.suf + b.pre);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].lc = tree[node].rc = s[l];
            tree[node].pre = tree[node].suf = tree[node].mx = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].lc = tree[node].rc = c;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};