class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i = 0;
        while (i < arr.size()) {
            bool found = false;
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j][0] == arr[i]) {
                    for (int k = 0; k < pieces[j].size(); k++) {
                        if (i >= arr.size() || arr[i] != pieces[j][k])
                            return false;
                        i++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};