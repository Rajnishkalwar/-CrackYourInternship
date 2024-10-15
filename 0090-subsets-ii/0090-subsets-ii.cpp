class Solution {
public:
    void recSubset(int index,vector<int> ds,vector<vector<int>>&ans,vector<int>&nums, int n){
            ans.push_back(ds);
          
          for(int i=index;i<n;i++){
          if(i!=index && nums[i]==nums[i-1]) continue;
          ds.push_back(nums[i]);
          recSubset(i+1,ds,ans,nums,n);
          ds.pop_back();
    }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
         int n=nums.size();
         vector<int> ds;
         recSubset(0,ds,ans,nums,n);
         return ans;
         
        
    }
};