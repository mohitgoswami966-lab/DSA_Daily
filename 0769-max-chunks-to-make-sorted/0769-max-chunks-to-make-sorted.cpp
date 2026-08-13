class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int expSum=0;
        int currSum=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            expSum+=i;
            currSum+=arr[i];
            if(expSum==currSum) count++;
        }
        return count;
    }
};