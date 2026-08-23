class Solution {
public:
    bool sumGame(string num) {
        double res=0;
        double n=num.size();
        for(int i=0;i<n;i++){
            double sign=0;
            if(i<n/2) sign=1;
            else sign=-1;
            double value;
            if(num[i]=='?') value=4.5;
            else value=num[i]-'0';
            res+=sign*value;
        }
        if(res!=0.0) return true;
        return false;
    }
};