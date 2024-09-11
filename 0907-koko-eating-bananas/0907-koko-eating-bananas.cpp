class Solution {
public:
    int findMax(vector<int>& piles){
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);

        }
        return maxi;
    }

    long long calculateHours(vector<int>& piles, int index){
        long long hours=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            hours+=ceil((double)(piles[i])/(double) (index));
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
          int low=1;
          int high=findMax(piles);
          int ans=-1;
          while(low<=high){
            int mid=low+(high-low)/2;
            long long res=calculateHours(piles,mid);
                if(res<=h){
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