class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int a=nums[i];
            int b=0;
            if(a>0){
                b=(i+a)%n;
            }
            else{
                b=(i+(n-abs(a)))%n;
                if(b<0){
                    b+=n;
                }
            }
            ans[i]=nums[b];
        }
        return ans;
    }
};