class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> even;
        stack<int> odd;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even.push(nums[i]);
            else{
                odd.push(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ans[i]=even.top();
                even.pop();
            }
            else{
                ans[i]=odd.top();
                odd.pop();
            }
        }
        return ans;
    }
};