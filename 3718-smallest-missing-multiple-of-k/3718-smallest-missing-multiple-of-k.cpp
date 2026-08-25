class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int p=k;
        unordered_set<int>s;
        for(auto it:nums)
        {
            s.insert(it);
        }

        bool flag=true;
        while(flag)
        {
            if(s.count(k)>0)
            {
                k+=p;
            }
            else
            {
                flag=false;

            }
        }
        return k;
    }
};