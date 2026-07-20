class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int cnt=0;

        vector<long long>pre(n);
        pre[0]=nums[0];
        if(pre[0]>0)cnt++;
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
            if(pre[i]>0) cnt++;
        }
        return cnt;
    }
};