class Solution {
public:
    int calculateSplit(vector<int>& nums, int sum){
        int split=1;
        int lastarr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(lastarr+nums[i]<=sum){
                lastarr+=nums[i];
            }
            else{
                split++;
                lastarr=nums[i];
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
             int splitcnt=calculateSplit(nums,mid);
            if(splitcnt>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }    
        }
         return low;
   }
};