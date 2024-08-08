class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIndex=-1;
        int lastIndex=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
            if(firstIndex==-1) firstIndex=i;
            lastIndex=i;
            }
        }
        return {firstIndex,lastIndex};
        
    }
};