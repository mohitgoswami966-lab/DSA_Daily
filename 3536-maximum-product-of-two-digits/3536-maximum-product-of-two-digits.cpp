class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        int a=n;
        while(a>0){
            int r=a%10;
            arr.push_back(r);
            a=a/10;
        }
        sort(arr.begin(),arr.end());
        int b=arr.size()-1;
        int max1=arr[b];
        int max2=arr[b-1];
        int ans=max1*max2;
        return ans;
    }
};