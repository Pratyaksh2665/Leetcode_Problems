class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int maxm=INT_MIN;
        int minm=INT_MAX;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            maxm=max(maxm,nums[i]);
            minm=min(minm,nums[i]);
            s.insert(nums[i]);

        }
        vector<int>ans;
        for(int i=minm+1;i<maxm;i++)
        {
            if(s.count(i)==0)
            {
                ans.push_back(i);
            }
        }
        return ans;

    }
};