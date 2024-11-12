class Solution {
public:
   int atmostk(vector<int>& nums, int k) {
        int left = 0, cnt = 0;
        unordered_map<int, int> mpp;

        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            // Adjust the left pointer to maintain at most `k` distinct elements
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left++;
            }
            
            // Count subarrays ending at `right`
            cnt += (right - left + 1);
        }
        
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)- atmostk(nums,k-1);
    }
};