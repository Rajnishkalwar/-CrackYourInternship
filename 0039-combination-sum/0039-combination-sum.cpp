class Solution {
public:
    void calculateCombination(int index,int target,vector<int> ds,vector<int>& candidates, int n,vector<vector<int>>&ans){
        if(index==n){
            if(target==0){
                ans.push_back(ds);
               
            }
             return;
            
        }
        
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            calculateCombination(index,target-candidates[index],ds,candidates,n,ans);
            ds.pop_back();
        }
        calculateCombination(index+1,target,ds,candidates,n,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> ds;
        vector<vector<int>>ans;
        calculateCombination(0,target,ds,candidates,n,ans);
        return ans;
        
    }
};