class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;

        for(auto it:nums)
        {
            pq1.push(abs(it));
            pq2.push(abs(it));
        }
        long long ans = 0;
        int count = 0;
        bool pos = true;
        while(count<n)
        {
            if(pos)
            {
                int x = pq1.top();
                ans+=(x*x);
                pq1.pop();
            }
            else
            {
                int y = pq2.top();
                ans-= (y*y);
                pq2.pop();
            }
            pos=!pos;
            count++;
        }

        return ans;
    }
};