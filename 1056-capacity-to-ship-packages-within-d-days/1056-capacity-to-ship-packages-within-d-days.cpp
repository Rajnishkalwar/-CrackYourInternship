class Solution {
public:
    int calculateCapacity(vector<int>& weights, int days,int capacity){
        int cnt=1;
        int n=weights.size();
        int load=0;

        for(int i=0;i<n;i++){
            if(load +weights[i]>capacity){
                cnt++;
                load=weights[i];
            }  
            else{
                load+=weights[i];
            } 
        }
        // if(load){
        //     cnt++;
        // }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int n=weights.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(weights[i],maxi);
            sum+=weights[i];
        }
        int low=maxi;
        int high=sum;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(calculateCapacity(weights,days,mid)){
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