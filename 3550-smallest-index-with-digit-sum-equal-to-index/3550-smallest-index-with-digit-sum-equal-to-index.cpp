class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int sum=0;
            while(a>0){
                int b=a%10;
                sum+=b;
                a=a/10;
            }
            if(sum==i){
                ans=i;
                break;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};