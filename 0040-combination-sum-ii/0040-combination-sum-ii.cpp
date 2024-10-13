class Solution {
public:
      void calculateCombination(int index,int target,vector<int>&ds,vector<int>& candidates, int n,vector<vector<int>>&ans){
        
        if(target==0){
                ans.push_back(ds);  
                return;    
        }
        for(int i=index;i<n;i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            calculateCombination(i+1,target-candidates[i],ds,candidates,n,ans);
            ds.pop_back();
        }   
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int> ds;
        vector<vector<int>>ans;
        calculateCombination(0,target,ds,candidates,n,ans);
        return ans;
        
    }
};