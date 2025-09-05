class Solution {
public:
    int bitcount(long long n){
        int cnt=0;
        while(n>0){
            if(n&1) cnt++;
            n=n>>1;
        }
        return cnt;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(long long k=1;k<=60;k++){
            long long diff=num1-(1LL*k*num2);
            if(diff<0) break;
            int bc=bitcount(diff);
            if(bc<=k&&k<=diff) return (int)k;
        }
        return -1;
    }
};
