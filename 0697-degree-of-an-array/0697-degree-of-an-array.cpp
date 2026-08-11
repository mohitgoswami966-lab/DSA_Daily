class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxFreq=mp[nums[0]];
        for(int i=1;i<nums.size();i++){
            maxFreq=max(maxFreq,mp[nums[i]]);
        }
        int ans=nums.size();
        for(auto it:mp){
            int val=it.first;
            if(it.second==maxFreq){
                int left=-1;
                int right=-1;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]==val){
                        if(left==-1) left=i;
                        right=i;
                    }
                }
                ans=min(ans,right-left+1);
            }
        }
        return ans;
    }
};