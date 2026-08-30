class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int k=0;
        while(k<n)
        {
            if(nums[k]>nums[j])
            {
                j=k;
            }
            if(nums[k]<nums[i])
            {
                i=k;
            }
            k++;
        }

        int one = max(i,j)+1;
        int two = n-min(i,j);
        int three = min(i,j)+1+n-max(i,j);

        return min(one , min(two , three));
    }
};