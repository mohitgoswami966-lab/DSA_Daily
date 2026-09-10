class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int cmax=nums[0]; 
       int cmin=nums[0]; 
       int ans=nums[0];
       for(int i=1;i<nums.size();i++){
        int n=nums[i];
        if(n<0){
            swap(cmin,cmax);
        }
        cmax=max(n,cmax*n);
        cmin=min(n,cmin*n);
        ans=max(ans,cmax);
       } 
       return ans;
    }
};