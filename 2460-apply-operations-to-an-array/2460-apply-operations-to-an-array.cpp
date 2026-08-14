class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i+1<n && nums[i]==nums[i+1]){
                ans[i]=nums[i]*2;
                nums[i+1]=0;
                i++;
            }
            else{
                ans[i]=nums[i];
            }
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(ans[i]!=0){
                ans[j]=ans[i];
                j++;
            }
        }
        while(j<n){
            ans[j]=0;
            j++;
        }
        return ans;
    }
};