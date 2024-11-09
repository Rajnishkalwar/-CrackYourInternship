class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxLen=INT_MIN;
        int zero_num=0;
       while(r<nums.size()){
        if(nums[r]==0){
            zero_num++;
        }
        if(zero_num>k){
            if(nums[l]==0) zero_num--;
            l++;
        }
        if(zero_num<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
       }
       return maxLen;
        
    }
};