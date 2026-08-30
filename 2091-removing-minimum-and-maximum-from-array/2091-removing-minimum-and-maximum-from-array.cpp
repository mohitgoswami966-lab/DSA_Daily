class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int miniINDEX=0;
        int maxiINDEX=0;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini){
                miniINDEX=i;
            }
            if(nums[i]==maxi){
                maxiINDEX=i;
            }
        }
        int n=nums.size();
        int diffFromStart=max(miniINDEX,maxiINDEX)+1;
        int diffFromEnd=n-min(miniINDEX,maxiINDEX);
        int OneStartOneEnd=(min(miniINDEX, maxiINDEX) + 1)+ (n - max(miniINDEX, maxiINDEX));
        int ans=min({diffFromStart,diffFromEnd,OneStartOneEnd});
        return ans;
    }
};