class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            if(j<nums.size() && ((nums[i]%2==0 && nums[j]%2==0)||(nums[i]%2!=0 && nums[j]%2!=0))){
                return false;
                break;
            }
        }
        return true;
    }
};