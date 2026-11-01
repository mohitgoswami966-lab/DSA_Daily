class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
        }
        long long moves = 0;
        for (int x : nums) moves += x - mn;
        return moves;
    }
};