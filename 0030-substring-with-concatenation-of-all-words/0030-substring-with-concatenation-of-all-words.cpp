
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int totalWords = words.size();

        unordered_map<string, int> mp;

        for(int i = 0; i < totalWords; i++) {
            mp[words[i]]++;
        }

        for(int i = 0; i < wordLen; i++) {

            int left = i;
            int count = 0;

            unordered_map<string, int> seen;

            for(int j = i; j + wordLen <= n; j += wordLen) {

                string word = s.substr(j, wordLen);

                if(mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
                else {
                    seen[word]++;
                    count++;

                    while(seen[word] > mp[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if(count == totalWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
            }
        }

        return ans;
    }
};
