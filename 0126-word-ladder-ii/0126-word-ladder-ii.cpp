class Solution {
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string b;
private:
    void dfs(string word,vector<string> &seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int step=mpp[word];
        int sz=word.size();
        for(int i=0;i<sz;i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(mpp.count(word)>0 && mpp[word]+1==step){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        b=beginWord;
        mpp[beginWord]=1;
        st.erase(beginWord);
        int sz=beginWord.size();
        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();
            if(word==endWord) break;
            for(int i=0;i<sz;i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word); 
                        mpp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};