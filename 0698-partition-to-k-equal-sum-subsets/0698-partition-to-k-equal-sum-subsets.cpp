class Solution {
public:

    bool helper(vector<int>& nums, vector<bool>& vis, int start,
                int sum, int target, int k)
    {
        if(k==1) return true;

        if(sum==target)
        {
            return helper(nums, vis, 0, 0, target, k-1);
        }

        for(int i=start;i<nums.size();i++)
        {
            if(vis[i]) continue;

            if(sum+nums[i]>target) continue;

            vis[i]=true;

            if(helper(nums, vis, i+1, sum+nums[i], target, k))
                return true;

            vis[i]=false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum=0;

        for(auto x:nums)
            sum+=x;

        if(sum%k!=0) return false;

        int target=sum/k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0]>target) return false;

        vector<bool> vis(nums.size(),false);

        return helper(nums, vis, 0, 0, target, k);
    }
};