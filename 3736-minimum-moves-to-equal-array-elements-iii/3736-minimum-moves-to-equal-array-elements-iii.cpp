class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mn=max(mn,nums[i]);
        }
        long long moves = 0;
        for (int x : nums) moves += mn-x;
        return moves;
    }
};