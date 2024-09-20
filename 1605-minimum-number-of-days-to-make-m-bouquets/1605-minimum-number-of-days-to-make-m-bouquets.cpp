class Solution {
public:
int ready(vector<int>& bloomDay, int m, int k,int day){
    int n=bloomDay.size();
    int phool=0;
    int boknumber=0;
    for(int i=0;i<n;i++){
       if(bloomDay[i]<=day){
          phool++;
       }
       else{
        boknumber+=phool/k;
        phool=0;

       }
    }
    boknumber+=phool/k;
    return boknumber>=m;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if(val>n){
            return -1;
        }
        for(int i=0;i<n;i++){
            mini=min(bloomDay[i],mini);
            maxi=max(bloomDay[i],maxi);
        }
        // for(int i=mini;i<=maxi;i++){
        //    if( ready(bloomDay,m,k,i)){
        //     return i;
        //    }
        // } 
        int low=mini;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(ready(bloomDay,m,k,mid)){
               
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }   
};