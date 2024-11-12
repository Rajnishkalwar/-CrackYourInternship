class Solution {
public:
    int binarysum(vector<int>& nums, int goal){
        int left=0;
        int right=0;
        int sum=0;
        int cnt=0; 
        if(goal<0 ) return 0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum=sum-nums[left];
                left++;
            }
                cnt+=(right-left+1); 
                right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return binarysum(nums,goal)- binarysum(nums, goal-1);
        
    }
};