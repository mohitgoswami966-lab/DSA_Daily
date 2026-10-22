class Solution {
private:
    int solve(vector<int> weights,int days,int limit){
        int day=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>limit){
                day++;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        int ans=0;
        for(int i=0;i<weights.size();i++){
            low=max(low,weights[i]);
            high += weights[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(weights,days,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};