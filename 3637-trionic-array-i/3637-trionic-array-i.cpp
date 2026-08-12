class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        int start=i;
        while(i+1<nums.size() && nums[i]<nums[i+1]){
            i++;
        }
        if(i==start) return false;
        start=i;
        while(i+1<nums.size() && nums[i]>nums[i+1]){
            i++;
        }
        if(i==start){
            return false;
        }
        start=i;
        while(i+1<nums.size() && nums[i]<nums[i+1]){
            i++;
        }
        if(i==start){
            return false;
        }
        return i==nums.size()-1;
    }
};