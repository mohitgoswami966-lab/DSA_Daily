class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count=0;
        long long expSum=0;
        long long currSum=0;
        vector<int> a=arr;
        sort(a.begin(),a.end());
        for(int i=0;i<arr.size();i++){
            expSum +=a[i];
            currSum +=arr[i];
            if(expSum==currSum) count++;
        }
        return count;
    }
};