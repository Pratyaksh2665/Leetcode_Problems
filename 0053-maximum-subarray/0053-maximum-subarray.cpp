class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxm=INT_MIN;
        int sum=0;
        for(auto it:nums)
        {
            maxm=max(maxm,it);
            sum+=it;
            maxm=max(maxm,sum);
            if(sum<0)
            {
                
                sum=0;
            }
        }
        return maxm;
    }
};