class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(auto it:nums)mp[it]++;

        for(auto it:mp)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }        
        vector<int>ans;
        while(pq.size()>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};