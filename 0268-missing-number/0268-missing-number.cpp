class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1,0);
        for(int i=0;i<n;i++){
            ans[nums[i]]++;
        }
        int res;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0){
                res=i; 
            }
        }
        return res;
        
    }
};