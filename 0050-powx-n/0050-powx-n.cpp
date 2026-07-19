class Solution {
private:
    double findpow(double s,int n){
        if(n==0) return 1;
        double half=findpow(s,n/2);
        if(n%2==0){
            return half*half;
        }
        else{
            return half*half*s;
        }
    }
public:
    double myPow(double x, int n) {
        long long pow=n;
        if(pow<0){
            x=1/x;
            pow=-pow;
        }
        return findpow(x,pow);
    }
};