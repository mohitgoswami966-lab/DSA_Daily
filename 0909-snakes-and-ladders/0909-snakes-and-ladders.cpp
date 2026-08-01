class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;
        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();
            if (curr == n * n)
                return dist;
            for (int dice = 1; dice <= 6 && curr + dice <= n * n; dice++) {
                int next = curr + dice;
                int x = next - 1;
                int r = x / n;
                int c = x % n;
                int row = n - 1 - r;
                if (r % 2 == 1)
                    c = n - 1 - c;
                if (board[row][c] != -1)
                    next = board[row][c];
                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, dist + 1});
                }
            }
        }
        return -1;
    }
};