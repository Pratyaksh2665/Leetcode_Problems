class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq; // fre , num
        vector<int>v;
        for(auto  it:arr) 
        {
            if(!mp.count(it)) v.push_back(it);//sari unique values store kr rhe h
            mp[it]++;
        }

        for(auto it:v)
        {
            pq.push({mp[it],it});
        }

        int count=0;
        int ans=0;
        while(pq.size()>0)
        {
            count+=pq.top().first;
            ans++;
            
            if(count>=n/2) return ans;
            pq.pop();
        }

        return ans;
      
    }
};