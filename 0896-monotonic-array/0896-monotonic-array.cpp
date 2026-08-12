class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int asc=0;
        int dsc=0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            if(j<nums.size() && nums[i]<nums[j]) asc++;
            else if(j<nums.size() && nums[i]>nums[j]) dsc++;
        }
        if(asc!=0 && dsc!=0) return false;
        return true;
    }
};