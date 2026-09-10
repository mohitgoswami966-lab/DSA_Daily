class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int firstE=0;
        int firstC=0;
        int SecondE=0;
        int SecondC=0;
        for(int i=0;i<nums.size();i++){
            if(firstE==nums[i]) firstC++;
            else if(SecondE==nums[i]) SecondC++;
            else if(firstC==0){
                firstE=nums[i];
                firstC=1;
            }
            else if(SecondC==0){
                SecondE=nums[i];
                SecondC=1;
            }
            else{
                firstC--;
                SecondC--;
            }
        }
        firstC=0;
        SecondC=0;
        for(int i=0;i<nums.size();i++){
            if(firstE==nums[i]) firstC++;
            else if(SecondE==nums[i]) SecondC++;
        }
        int a=nums.size()/3;
        if(firstC>a){
            ans.push_back(firstE);
        }
        if(firstE!=SecondE && SecondC>a){
            ans.push_back(SecondE);
        }
        return ans;
    }
};