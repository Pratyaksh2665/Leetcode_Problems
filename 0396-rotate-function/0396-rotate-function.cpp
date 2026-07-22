class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long long maxm=LLONG_MIN;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            ans+=(nums[i]*i);
            sum+=nums[i];
        }
        maxm=max(maxm,ans);
        long long last=ans;
        for(int k=1;k<n;k++)
        {
            long long next=last+(sum-(n*nums[n-k]));
            maxm=max(maxm,next);
            last=next;
        }
        return (int)maxm;
        
    }
};