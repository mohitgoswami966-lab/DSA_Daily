class Solution {
private:
    void merge(vector<int> &nums,int left,int mid,int right,int &ans){
        int j=mid+1;
        for(int i=left;i<=mid;i++){
            while(j<=right && nums[i]>(long long)2*nums[j]) j++;
            ans+= j-(mid+1);
        }
        j=mid+1;
        int start=left;
        int n=right-left+1;
        vector<int> temp(n,0);
        int i=0;
        while(left<=mid && j<=right){
            if(nums[left]<=nums[j]){
                temp[i++]=nums[left++];
            }
            else{
                temp[i++]=nums[j++];
            }
        }
        while(left<=mid){
            temp[i++]=nums[left++];
        }
        while(j<=right){
            temp[i++]=nums[j++];
        }
        i=0;
        for(int j=start;j<=right;j++){
            nums[j]=temp[i++];
        }
    }
    void mergeSort(vector<int> &nums,int left,int right,int &ans){
        if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid,ans);
        mergeSort(nums,mid+1,right,ans);
        merge(nums,left, mid,right,ans);}
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};