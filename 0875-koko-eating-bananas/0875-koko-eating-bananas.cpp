class Solution {
private:
    long long solve(vector<int> piles,int hour){
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            sum+= (piles[i]+hour-1)/hour;
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};