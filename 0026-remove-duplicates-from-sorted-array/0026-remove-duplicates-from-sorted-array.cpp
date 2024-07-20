class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        int k;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set.insert(nums[i]);

        }
        int j=0;
         k=set.size();
        for(auto it: set){
            nums[j++]=it;
             
        }
       
       
        return k;
        
    }
};