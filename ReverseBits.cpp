class Solution {
public:
    int reverseBits(int n) {
        long long res=0;
        for(int i=0;i<32;i++){
            long long bit=(n>>i)&1;
            res=res|(bit<<(31-i));
        }
        return (int) res;
    }
};
