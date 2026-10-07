class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=nums.size()-1;
        vector<int>ans;
        while(i<=j)
        {
            int x = nums[i]*nums[i];
            int y= nums[j]*nums[j];
            if(x>=y)
            {
                ans.push_back(x);
                i++;
            
            }
            else
            {
                ans.push_back(y);
                j--;
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};