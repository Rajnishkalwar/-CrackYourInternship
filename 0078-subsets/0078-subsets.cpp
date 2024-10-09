class Solution {
public:
    void subsequence(int index,vector<int>&ds,vector<int>&nums,int n,vector<vector<int>>&ans)
    {
        if(index==n){
        ans.push_back(ds);  
        return;
        }
        ds.push_back(nums[index]);
        subsequence(index+1,ds,nums,n,ans);
        ds.pop_back();
        subsequence(index+1,ds,nums,n,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> ans;
    vector<int> ds;
    subsequence(0,ds,nums,n,ans);  
    return ans;

    
    }
};