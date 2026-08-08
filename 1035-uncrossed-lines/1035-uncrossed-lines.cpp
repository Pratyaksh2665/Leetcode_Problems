class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2,
               int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int len = 0;

        if(nums1[i] == nums2[j])
        {
            len = 1 + helper(nums1, nums2, i-1, j-1, dp);
        }
        else
        {
            len = max(
                helper(nums1, nums2, i, j-1, dp),
                helper(nums1, nums2, i-1, j, dp)
            );
        }

        return dp[i][j] = len;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return helper(nums1, nums2, n1-1, n2-1, dp);
    }
};