class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0,y=0;
        for(auto i:commands){
            if(i=="UP") x--;
            else if(i=="RIGHT") y++;
            else if(i=="LEFT") y--;
            else if(i=="DOWN") x++;
        }
        return (x*n)+y;
    }
};