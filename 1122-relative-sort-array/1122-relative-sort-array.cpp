class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int> ans;
        vector<int> a1;
        unordered_set<int> s(arr2.begin(),arr2.end());
        unordered_map<int,int> freq;
        for(int i=0;i<arr1.size();i++){
            freq[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            int a=arr2[i];
            while(freq[a]--){
                ans.push_back(a);
            }
        }
        for(int i=0;i<arr1.size();i++){
            if(s.find(arr1[i])==s.end()){
                a1.push_back(arr1[i]);
            }
        }
        sort(a1.begin(),a1.end());
        for(int i=0;i<a1.size();i++){
            ans.push_back(a1[i]);
        }
        return ans;
    }
};