class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int a=nums[i];
            sum+=nums[i];
            if(j<nums.size() && a+1!=nums[j]) break;
        }
        unordered_set s(nums.begin(),nums.end());
        while(true){
            if(s.find(sum)==s.end()){
                break;
            }
            sum+=1;
        }
        return sum;
    }
};