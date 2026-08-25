class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> present(101,false);
        for(auto num:nums){
            if(num%k==0){
                present[num/k]=true;
            }
        }
        for(int i=1;i<=101;i++){
            if(!present[i]){
                return i*k;
            }
        }
        return -1;
    }
};