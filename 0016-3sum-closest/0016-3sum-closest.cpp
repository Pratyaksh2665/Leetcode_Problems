class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int minm = INT_MAX;     
        int res = 0;           
        for(int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n - 1;
           
            int t = target - nums[i];

            while(l < r) {
                int sum = nums[l] + nums[r];
                int diff = abs(sum - t);

                
                if(diff < minm) {
                    minm = diff;
                    res = sum + nums[i];  
                }

                if(sum < t) l++;
                else r--;
            }
        }
        return res;
    }
};
