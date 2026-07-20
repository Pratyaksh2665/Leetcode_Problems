class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxm=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int ans=1;
            for(int j=i;j<n;j++)
            {
                ans*=nums[j];
                maxm=max(maxm,ans);
            }

        }
        return maxm;
    }
};