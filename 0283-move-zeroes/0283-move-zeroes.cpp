class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int noz=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) noz++;
            else ans.push_back(nums[i]);
        }
        for(int i=0;i<noz;i++) ans.push_back(0);
        nums=ans;
        return;
    }
};