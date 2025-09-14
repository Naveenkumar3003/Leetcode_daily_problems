class Solution {
public:
    int maxFreqSum(string s) {
        int a=0,e=0,i=0,o=0,u=0,cons=0;
        int lettercnt[26]={0};
        int vowmax=0,consmax=0;
        for(char c:s){
            c=tolower(c);
            if(!isalpha(c)) continue;
            if(c=='a') {a=a+1; vowmax=max(vowmax,a);}
            else if(c=='e') {e=e+1;vowmax=max(vowmax,e);}
            else if(c=='i') {i=i+1;vowmax=max(vowmax,i);}
            else if(c=='o') {o=o+1;vowmax=max(vowmax,o);}
            else if(c=='u') {u=u+1;vowmax=max(vowmax,u);}
            else{
                int ind=c-'a';
                ++lettercnt[ind];
                consmax=max(consmax,lettercnt[ind]);
            }
        }
        return vowmax+consmax;
    }
};
