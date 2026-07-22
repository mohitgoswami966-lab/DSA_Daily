class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s=nums.size();
        k=k%s;
        vector<int> temp=nums;
        for(int i=0;i<s;i++){
            int j=i+k;
            if(j>s-1){
                int l=i+k;
                j=l-s;
                temp[j]=nums[i];
            }
            else{
                temp[j]=nums[i];
            }
        }
        nums=temp;
    }
};