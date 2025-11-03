class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        for(int i=1;i<colors.length();i++){
            if(colors[i]==colors[i-1]){
                if(neededTime[i]<=neededTime[i-1]){
                    time+=neededTime[i];
                    neededTime[i]=neededTime[i-1];
                }
                else{
                    time+=neededTime[i-1];
                }
            }
        }
        return time;
    }
};
