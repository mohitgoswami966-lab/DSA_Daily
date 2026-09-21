class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<>> pq;
        sort(intervals.begin(), intervals.end());
        pq.push(intervals[0][1]);
        long long int sol = 0;
        int n = intervals.size();
        for(int i= 1; i < n; i++){
            while(!pq.empty() && pq.top() < intervals[i][0]){
                pq.pop();
            }
            sol += pq.size();
            pq.push(intervals[i][1]);
        }
        return sol;
    }
};