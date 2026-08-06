class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        for(int i=0;i<items.size();i++){
            string a=items[i][0];
            string b=items[i][1];
            string c=items[i][2];
            if(ruleKey=="type" && a==ruleValue) count++;
            else if(ruleKey=="color" && b==ruleValue) count++;
            else if(ruleKey=="name" && c==ruleValue) count++;
        }
        return count;
    }
};