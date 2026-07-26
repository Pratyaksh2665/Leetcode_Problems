class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        while(i<n)
        {
            pq.push(nums[i]);
            while(pq.size()>k)pq.pop();
            i++;
        }
        return pq.top();
    }
};