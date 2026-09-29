class Solution {
public:
    string reverseParentheses(string s) {
        string a = "";
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') {
                string let = "";
                while(st.top() != '(') {
                    let += st.top();
                    st.pop();
                }
                st.pop();

                for(int j = 0; j < let.size(); j++) {
                    st.push(let[j]);
                }
            }
            else {
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
            a += st.top();
            st.pop();
        }
        reverse(a.begin(), a.end()); 
        return a;
    }
};