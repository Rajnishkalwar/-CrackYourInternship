class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int maxfreq=0;
        int maxlen=0;
        unordered_map<char,int> hashset;
        while(right<s.size()){
            hashset[s[right]-'A']++;
            maxfreq=max(maxfreq,hashset[s[right]-'A']);
            if((right-left+1)-maxfreq>k){
                hashset[s[left]-'A']--;
                maxfreq=0;
                left++;
            }
            if((right-left+1)-maxfreq<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;    
    }
};