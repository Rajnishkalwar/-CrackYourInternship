class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        unordered_set<int> st;
        int l=0;
        int maxAns=0;
        for(int r=0;r<s.length();r++){
            if(st.find(s[r])!=st.end()){
                while(l<r and st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            maxAns=max(maxAns,r-l+1);

        }
        return maxAns;
         
    }
    
};