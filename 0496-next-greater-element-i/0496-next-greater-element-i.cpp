class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        unordered_map<int,int> mp;
        for(auto num:nums2){
            while(!s.empty() && s.top()<num){
                mp[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        for(auto i:nums1){
            if(mp.count(i)){
                ans.push_back(mp[i]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};