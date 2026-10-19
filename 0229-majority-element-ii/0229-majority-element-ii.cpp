class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int firstE=0;
        int firstC=0;
        int secondE=0;
        int secondC=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==firstE) firstC++;
            else if(nums[i]==secondE) secondC++;
            else if(firstC==0){
                firstE=nums[i];
                firstC++;
            }
            else if(secondC==0){
                secondE=nums[i];
                secondC++;
            }
            else{
                firstC--;
                secondC--;
            }
        }
        firstC=0;
        secondC=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==firstE) firstC++;
            if(nums[i]==secondE) secondC++;
        }
        int n=nums.size();
        int k=n/3;
        if(firstC>k) ans.push_back(firstE);
        if(secondC>k && secondE!=firstE) ans.push_back(secondE);
        return ans;
    }
};