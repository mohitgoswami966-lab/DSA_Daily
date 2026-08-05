class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int count=1;
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+= widths[s[i]-'a'];
            if(sum>100){
                i--;
                count++;
                sum=0;
            }
        }
        return {count,sum};
    }
};