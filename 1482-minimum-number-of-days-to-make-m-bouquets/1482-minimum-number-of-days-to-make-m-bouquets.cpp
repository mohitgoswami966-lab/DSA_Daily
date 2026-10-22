class Solution {
private:
    bool solve(vector<int> bloomDay,int m,int k,int mid){
        int count=0;
        int noofb=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                noofb += (count/k);
                count=0;
            }
        }
        noofb += (count/k);
        return noofb>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=(long long)m *(long long)k;
        if(val>bloomDay.size()) return -1;
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};