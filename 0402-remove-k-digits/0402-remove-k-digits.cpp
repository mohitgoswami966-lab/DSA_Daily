class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.size();i++){
            while(!s.empty() && k>0 && (s.top()-'0')>(num[i]-'0')){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string result="";
        while(!s.empty()){
            char a=s.top();
            s.pop();
            result += a;
        }
        reverse(result.begin(),result.end());
        int i=0;
        while(result[i]=='0' && !result.empty()){
            i++;
        }
        string ans=result.substr(i);
        if(ans.empty()) return "0";
        return ans;
    }
};