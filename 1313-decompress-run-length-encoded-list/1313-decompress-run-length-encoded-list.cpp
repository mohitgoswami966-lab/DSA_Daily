class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<nums.size()/2){
            int freq=nums[2*i];
            int val=nums[2*i+1];
            while(freq){
                ans.push_back(val);
                freq--;
            }
            i++;
        }
        return ans;
    }
};