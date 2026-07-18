class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minm=INT_MAX;
        int maxm=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxm=max(maxm,nums[i]);
            minm=min(minm,nums[i]);
        }
        int gcd=1;
        for(int i=2;i<=minm;i++)
        {
            if(minm%i==0 && maxm%i==0) gcd=i;
        }
        return gcd;
        
    }
};