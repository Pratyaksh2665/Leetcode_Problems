class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        long long maxm = 0;
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
            sum+=nums[j];
            mp[nums[j]]++;
            if(j-i+1 == k)
            {
                if(mp.size()==k)maxm=max(maxm,sum);
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }

        return maxm;
    }
};