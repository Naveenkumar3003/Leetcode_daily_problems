class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int num:nums){
            st.push_back(num);
            while(st.size()>1){
                int a=st.back(); st.pop_back();
                int b=st.back(); st.pop_back();
                int g=__gcd(a,b);
                if(g>1){
                    long long lcm=(1LL*a*b)/g;
                    st.push_back((int)lcm);
                }
                else{
                    st.push_back(b);
                    st.push_back(a);
                    break;
                }
            }
        }
        return st;
    }
};
