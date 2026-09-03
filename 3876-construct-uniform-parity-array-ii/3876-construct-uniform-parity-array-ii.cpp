class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = 0;
        int even=0;
        int minm=INT_MAX;
        for(auto it:nums1)
        {
            if(it%2==0) even++;
            else odd++;

            minm=min(minm,it);
        }
        if(odd==0 || even==0) return true;

        if(minm%2==0)
        {
            if(odd!=0) return false;
        }
        return true;
    }
};