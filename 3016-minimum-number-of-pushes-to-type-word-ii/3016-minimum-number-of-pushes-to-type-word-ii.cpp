class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();

        vector<int>cnt(26,0);
        for(auto it:word) cnt[it-'a']++;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>0)
            {
                pq.push({cnt[i],i});
            }
        }
        int ans=0;
        int s=pq.size();
        int p=s/8;
        int rem=s%8;
        int count=1;
        for(int i=0;i<p;i++)
        {
            
            for(int j=0;j<8;j++)
            {
                if(pq.size()==0)break;
                ans+=(count*cnt[pq.top().second]);
                pq.pop();
            }
            count++;
        }
        while(pq.size()>0)
        {
            ans+=(count*cnt[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};