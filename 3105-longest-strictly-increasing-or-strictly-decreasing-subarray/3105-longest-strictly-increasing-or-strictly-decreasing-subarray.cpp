class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxCount=1;
        int count=1;
        for(int i=0;i<nums.size()-1;i++){
            int a=nums[i];
            int b=nums[i+1];
            if(b>a) count++;
            else{
                maxCount=max(maxCount,count);
                count=1;
            }
        }
        maxCount=max(maxCount,count);
        count=1;
        for(int i=0;i<nums.size()-1;i++){
            int a=nums[i];
            int b=nums[i+1];
            if(b<a) count++;
            else{
                maxCount=max(maxCount,count);
                count=1;
            }
        }
        maxCount=max(maxCount,count);
        return maxCount;
    }
};