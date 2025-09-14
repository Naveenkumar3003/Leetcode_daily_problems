class Solution {
public:
    void convertlower(string &str){
        int n=str.length();
        for(int i=0;i<n;i++){
            str[i]=tolower(str[i]);
        }
    }
    void replaceVowels(string &str){
        for(int i=0;i<str.length();i++){
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
                str[i]='*';
            }
        }
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string,int> same;
        map<string,string> lR;
        map<string,string> vR;

        for(auto str:wordlist){
            same[str]=1;
            string lowered=str; convertlower(lowered);
            if(lR.count(lowered)==0) lR[lowered]=str;

            string vowRep=lowered; replaceVowels(vowRep);
            if(vR.count(vowRep)==0) vR[vowRep]=str;

        }
        vector<string> ans;
        for(auto qr:queries){
            string lowered=qr; convertlower(lowered);
            string vowRep=lowered; replaceVowels(vowRep);

            if(same[qr]) ans.push_back(qr);
            else if(lR.count(lowered)>0) ans.push_back(lR[lowered]);
            else if(vR.count(vowRep)>0) ans.push_back(vR[vowRep]);
            else ans.push_back("");
        }
        return ans;
    }
};
