class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==10)
            {
                if(mp[5]==0) flag=false;
                else
                {
                    mp[5]--;
                    if(mp[5]==0)
                    {
                        mp.erase(5);
                    }
                }
            }
            else if(arr[i]==20)
            {
                int x=0;
                if(mp.count(10)) x=mp[10];
                
                int y=0;
                if(mp.count(5)) y=mp[5];
                
                if(x>=1 && y>=1)
                {
                    mp[10]--;
                    mp[5]--;
                    if(mp[5]==0)
                    {
                        mp.erase(5);
                    }
                     if(mp[10]==0)
                    {
                        mp.erase(10);
                    }
                }
                else if(x==0 && y>=3)
                {
                    mp[5]--;
                    mp[5]--;
                    mp[5]--;
                    if(mp[5]==0)
                    {
                        mp.erase(5);
                    }
                    
                }
                else flag=false;
                
            }
            
            mp[arr[i]]++;
        }
        
        return flag;

    }
};