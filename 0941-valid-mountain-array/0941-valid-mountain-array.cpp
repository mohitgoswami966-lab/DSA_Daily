class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int ansi=0;
        int n=arr.size();
        if(arr.size()<3) return false;
        while(ansi+1<n && arr[ansi]<arr[ansi+1]) ansi++;
        if(ansi==0 || ansi==n-1) return false;
        while(ansi+1<n && arr[ansi]>arr[ansi+1]) ansi++;
        return ansi==n-1;
    }
};