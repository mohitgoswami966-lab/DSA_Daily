class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp=nums;
        int i=0;
        int j=1;
        for(int k=0;k<nums.size();k++){
            if(nums[k]>0){
                temp[i]=nums[k];
                i=i+2;
            }
            else{
                temp[j]=nums[k];
                j=j+2;
            }
        }
        return temp;
    }
};