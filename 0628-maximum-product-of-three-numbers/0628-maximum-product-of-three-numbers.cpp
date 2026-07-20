class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int x=nums[0];
        int y=nums[1];

        int n1=nums[n-1];
        int n2=nums[n-2];
        int n3=nums[n-3];


        return max(n1*n2*n3,x*y*n1);
    }
};