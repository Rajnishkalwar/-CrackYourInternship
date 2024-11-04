class Solution {
public:
    bool ispalindrome(int start,int end, string s){
       
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void fun(int index,string s,vector<string> &path,vector<vector<string>> &ans){
        if(index==s.size()){
            ans.push_back(path);
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                fun(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        fun(0,s,path,ans);
        return ans;
        
    }
};