class Solution {
private:
    vector<int> findnse(vector<int> nums){
        int n=nums.size();
        vector<int> ans(n,n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()  && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int> nums){
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            while(!s.empty()  && nums[s.top()]>nums[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findpge(vector<int> nums){
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            while(!s.empty()  && nums[s.top()]<nums[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findnge(vector<int> nums){
        int n=nums.size();
        vector<int> ans(n,n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()  && nums[s.top()]<=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    long long largesum(vector<int> nums){
        vector<int> next=findnge(nums);
        vector<int> prev=findpge(nums);
        long long total=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-prev[i];
            long long right=next[i]-i;
            total = total+(left*right)*nums[i]; 
        }
        return total;
    }
    long long smallsum(vector<int> nums){
        vector<int> next=findnse(nums);
        vector<int> prev=findpse(nums);
        long long total=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-prev[i];
            long long right=next[i]-i;
            total = total+(left*right)*nums[i]; 
        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long smallest=smallsum(nums);
        long long largest=largesum(nums);
        long long ans=largest-smallest;
        return ans;
    }
};