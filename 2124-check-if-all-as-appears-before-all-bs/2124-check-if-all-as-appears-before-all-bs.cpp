class Solution {
public:
    bool checkString(string s) {
        int counta=0;
        int countb=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                if(countb==0){
                    counta++;
                }
                else{
                    return false;
                }
            }
            else{
                countb++;
            }
        }
        return true;
    }
};