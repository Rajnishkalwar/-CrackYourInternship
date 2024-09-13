class Solution {
public:
int calculateDivisor(vector<int>& nums, int threshold,int divisor){
    int res=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        res+=ceil((double)(nums[i])/(double)(divisor));    
    }
    return res<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        int low=1;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(calculateDivisor(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;

            }
        }
        return ans;
          
        
    }
};