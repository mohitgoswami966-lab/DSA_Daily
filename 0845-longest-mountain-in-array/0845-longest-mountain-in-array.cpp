class Solution {
public:
    int longestMountain(vector<int>& arr) {
       int maxMnt = 0;
    
        int i = 1;
        while (i < arr.size()) {
            while(i < arr.size() && arr[i-1] == arr[i])
                ++i;
            
            int up = 0;
            while(i < arr.size() && arr[i-1] < arr[i]) {
                ++up;
                ++i;
            }
            
            int down = 0;
            while(i < arr.size() && arr[i-1] > arr[i]) {
                ++down;
                ++i;
            }
            
            if (up > 0 && down > 0)  
                maxMnt = max(maxMnt, up+down+1);
            
        }
        
        return maxMnt;
    }
};