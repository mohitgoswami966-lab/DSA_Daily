class Solution {
public:
    bool checkDivisibility(int n) {
        int a=n;
        int sum=0;
        int pro=1;
        while(a>0){
            int l=a%10;
            sum+=l;
            pro*=l;
            a=a/10;
        }
        int total=sum+pro;
        if(n%total==0) return true;
        return false;
    }
};