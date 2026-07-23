class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=nums.size();
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0;i<s;i++){
            int j=i+1;
            int k=s-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    set.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        for(auto a:set){
            output.push_back(a);
        }
        return output;
    }
};