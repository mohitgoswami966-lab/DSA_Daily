class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> curr(word2.size()+1,0);
        vector<int> next(word2.size()+1,0);
        for(int j=0;j<word2.size();j++){
            next[j]=word2.size()-j;
        }
        for(int i=word1.size()-1;i>=0;i--){
            curr[word2.size()]=word1.size()-i;
            for(int j=word2.size()-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j]){
                    ans=next[j+1];
                }
                else{
                    int insertAns=1+curr[j+1];
                    int deleteAns=1+next[j];
                    int replaceAns=1+next[j+1];
                    ans=min({insertAns,deleteAns,replaceAns});
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
};