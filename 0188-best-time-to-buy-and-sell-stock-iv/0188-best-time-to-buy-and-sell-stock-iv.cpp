class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2*k+1,0);
        vector<int> next(2*k+1,0);
        for(int index=n-1;index>=0;index--){
            for(int operation=0;operation<2*k;operation++){
                int profit=0;
                if(operation%2==0){
                    int buyKaro=-prices[index]+next[operation+1];
                    int skipKaro=0+next[operation];
                    profit=max(skipKaro,buyKaro);
                }
                else{
                    int sellKaro=prices[index]+next[operation+1];
                    int skipKaro=0+next[operation];
                    profit=max(skipKaro,sellKaro);
                }
                curr[operation]=profit;
            }
            next=curr;
        }
        return next[0];
    }
};