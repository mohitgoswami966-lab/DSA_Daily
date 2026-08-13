class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;

        for (int x : nums)
            mp[x]++;

        vector<pair<int,int>> v;

        for (auto x : mp)
            v.push_back({x.first, x.second});

        sort(v.begin(), v.end(), cmp);

        vector<int> ans;

        for (auto x : v) {
            for (int i = 0; i < x.second; i++)
                ans.push_back(x.first);
        }

        return ans;
    }
};