class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int s= nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0;i<s-3;i++){
            for(int j=i+1;j<s-2;j++){
                int low=j+1;
                int high=s-1;
                long long newtarget=(long long)target-(long long)nums[i]-(long long)nums[j];
                while(low<high){
                    if((long long)nums[low]+nums[high]==newtarget){
                        set.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                    else if(nums[low]+nums[high]<newtarget){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        for(auto a:set){
            output.push_back(a);
        }
        return output;
    }
};