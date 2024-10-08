class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int needed=target-nums[i];
            if(mpp.find(needed)!=mpp.end()){
                return {i,mpp[needed]};
            }
            mpp[nums[i]]=i;
        }
        return {};
        
    }
};