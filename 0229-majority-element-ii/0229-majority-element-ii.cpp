class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int firstC=0;
        int firstE=0;
        int secondE=0;
        int secondC=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==firstE) firstC++;
            else if(nums[i]==secondE) secondC++;
            else if(firstC==0){
                firstE=nums[i];
                firstC=1;
            }
            else if(secondC==0){
                secondE=nums[i];
                secondC=1;
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
            else if(nums[i]==secondE) secondC++;
        }
        int a=n/3;
        if(firstC>a){
            ans.push_back(firstE);
        }
        if(secondC>a && firstE!=secondE){
            ans.push_back(secondE);
        }
        return ans;
    }
};