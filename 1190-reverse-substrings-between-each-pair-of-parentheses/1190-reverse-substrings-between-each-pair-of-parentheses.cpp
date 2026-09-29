class Solution {
public:
    string reverseParentheses(string s) {
        string a="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                string let="";
                while(st.top()!='('){
                    char b=st.top();
                    st.pop();
                    let += b;
                }
                st.pop();
                for(int j=0;j<let.size();j++){
                    st.push(let[j]);
                }
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            char c=st.top();
            st.pop();
            a+=c;
        }
        reverse(a.begin(), a.end()); 
        return a;
    }
};