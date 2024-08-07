class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=0;
        int cnt=1;
        int lastNum=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastNum){
                cnt++;
                lastNum=nums[i];
            }
            else if(nums[i]!=lastNum){
                cnt=1;
                lastNum=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
        

        
    }
};