class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int countEven=0;
        int n=nums1.size();
        int countOdd=0;
        int mini=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) countEven++;
            else if(nums1[i]%2!=0) countOdd++;
            mini=min(mini,nums1[i]);
        }
        if(countEven==n||countOdd==n) return true;
        return (mini%2==1);
    }
};