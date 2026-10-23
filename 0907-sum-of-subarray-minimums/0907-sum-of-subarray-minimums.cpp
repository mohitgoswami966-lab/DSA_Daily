class Solution {
private:
    vector<int> findnse(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n,n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> next=findnse(arr);
        vector<int> prev=findpse(arr);
        long long total=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            long long left=i-prev[i];
            long long right=next[i]-i;
            total=(total+left*right%mod *arr[i]%mod)%mod;
        }
        return total;
    }
};