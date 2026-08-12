class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int second;
        for (int i = 0; i < encoded.size(); i++) {
            second = encoded[i];
            encoded[i] = first;
            first = first ^ second;
        }
        encoded.push_back(first);
        return encoded;
    }
};