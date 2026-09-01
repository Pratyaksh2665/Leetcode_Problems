class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=INT_MAX;
        int minlen=INT_MAX;
        int i=0,j=0;
        int sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                len=j-i+1;
                minlen=min(minlen,len);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(minlen==INT_MAX)return 0;
        return minlen;
        
    }
};