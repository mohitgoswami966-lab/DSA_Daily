class Solution {
public:
    int addDigits(int num) {
        int sum;
        int a=num;
        while(true){
            sum=0;
            while(a>0){
                sum+=a%10;
                a=a/10;
            }
            a=sum;
            if(a/10==0) break;
        }
        return sum;
    }
};