class Solution {
private:
    int gcd(int first,int second){
        while(second){
            int r=first%second;
            first=second;
            second=r;
        }
        return first;
    }
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        int ans=gcd(mini,maxi);
        return ans;
    }
};