class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> output;
        vector<int> prev;
        for(int i=0;i<=rowIndex;i++){
            vector<int> curr(i+1,1);
            for(int j=1;j<i;j++){
                curr[j]=prev[j-1]+prev[j];
            }
            prev=curr;
            output.push_back(curr);
        }
        return prev;
    }
};