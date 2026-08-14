class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
            s.push(nums[i]);
        }
        while(!s.empty()){
            int top=s.top();
            s.pop();
            ans.push_back(top);
        }
        return ans;
    }
};