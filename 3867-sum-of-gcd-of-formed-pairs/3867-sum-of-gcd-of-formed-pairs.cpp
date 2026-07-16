class Solution {
public:
    long long gcd(long long a ,long long b)
    {
        while(b)
        {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums)
    {
        int n=nums.size();

        vector<int>pref(n);
        pref[0]=nums[0];
        int maxm=pref[0];
        
        for(int i=1;i<n;i++)
        {
            maxm=max(maxm,nums[i]);

            pref[i]=gcd(nums[i],maxm);
        }

        sort(pref.begin(),pref.end());

        long long sum=0;
        int i = 0, j = n - 1;
        while(i < j)
        {
            sum += gcd(pref[i], pref[j]);
            i++;
            j--;
        }
        return sum;
        
    }
};