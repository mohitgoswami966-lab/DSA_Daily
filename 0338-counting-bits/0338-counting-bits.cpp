class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int x = 0; x <= n; x++) {
            int i=x;
            long long count = 0;
            if (i == 0)
                ans.push_back(0);
            else {
                while (i != 0) {
                    i = i & (i - 1);
                    count++;
                }
                ans.push_back(count);
            }
        }
        return ans;
    }
};