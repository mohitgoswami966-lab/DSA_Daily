class Solution {
public:
    bool checkValidString(string s) {
        int countO=0;
        int countC=0;
        int n=s.size();
        for(auto ch:s){
            if(ch=='(' || ch=='*') countO++;
            else countO--;
            if(countO<0) return false;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*') countC++;
            else countC--;
            if(countC<0) return false;
        }
        return true;
    }
};