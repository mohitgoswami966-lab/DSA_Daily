class Solution {
private:
    void merge(vector<int> &nums,int left,int mid,int right,int &ans){
        int j=mid+1;
        for(int i=left;i<=mid;i++){
            while(j<=right && nums[i]>(long long) 2*nums[j]) j++;
            ans += j-(mid+1);
        }
        int a=left;
        int b=mid+1;
        int size=right-left+1;
        vector<int> temp(size,0);
        int i=0;
        while(a<=mid && b<=right){
            if(nums[a]<=nums[b]) temp[i++]=nums[a++];
            else temp[i++]=nums[b++];
        }
        while(a<=mid) temp[i++]=nums[a++];
        while(b<=right) temp[i++]=nums[b++];
        i=0;
        for(int j=left;j<=right;j++){
            nums[j]=temp[i++];
        }
    }
    void mergeSort(vector<int> &nums,int left,int right,int &ans){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid,ans);
        mergeSort(nums,mid+1,right,ans);
        merge(nums,left,mid,right,ans);
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};