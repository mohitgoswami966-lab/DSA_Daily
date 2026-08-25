class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        for (int i = 0; i < envelopes.size(); i++) {
            envelopes[i][1] = -envelopes[i][1];
        }
        sort(envelopes.begin(), envelopes.end());
        vector<int> lis;
        for (int i = 0; i < envelopes.size(); i++) {
            int height = -envelopes[i][1];
            int index = lower_bound(lis.begin(), lis.end(), height) - lis.begin();
            if (index == lis.size()) {
                lis.push_back(height);
            } 
            else {
                lis[index] = height;
            }
        }
        return lis.size();
    }
};