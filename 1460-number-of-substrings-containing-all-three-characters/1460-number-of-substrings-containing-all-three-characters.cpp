class Solution {
public:
    int numberOfSubstrings(string s) {
         int lastposition[3]={-1,-1,-1};
         int cnt=0;
         for(int i=0;i<s.size();i++){
            lastposition[s[i]-'a']=i;
            if(lastposition[0]!=-1 && lastposition[1]!=-1 && lastposition[2]!=-1){
                 cnt=cnt+(1+min({lastposition[0],lastposition[1],lastposition[2]}));
            }
         }
         return cnt;   
    }
};