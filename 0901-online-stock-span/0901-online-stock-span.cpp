class StockSpanner {
    stack<pair<int,int>> s;
    int index=-1;
public:
    StockSpanner() {
        index=-1;
        while(!s.empty()) s.pop();
    }
    
    int next(int price) {
        index++;
        while(!s.empty() && s.top().first<=price){
            s.pop();
        }
        int ans;
        if(s.empty()){
            ans = index-(-1);
        }
        else{
            ans = index-s.top().second;
        }
        s.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */