class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int countE=0;
        int countO=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) countE++;
            else{
                countO++;
            }
        }
        vector<int> ans;
        while(countE--){
            ans.push_back(0);
        }
        while(countO--){
            ans.push_back(1);
        }
        return ans;
    }
};