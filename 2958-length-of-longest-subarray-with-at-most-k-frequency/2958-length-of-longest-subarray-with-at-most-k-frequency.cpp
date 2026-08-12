class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;
        int j = 0;
        int maxm = 0;

        bool possible = true;

        unordered_map<int,int> mp;

        while(j < n)
        {
            if(possible)
            {
                mp[nums[j]]++;

                if(mp[nums[j]] > k)
                {
                    possible = false;
                }
                else
                {
                    maxm = max(maxm, j-i+1);
                }

                j++;
            }
            else
            {
                while(i < j && nums[i] != nums[j-1])
                {
                    mp[nums[i]]--;
                    i++;
                }

                mp[nums[i]]--;
                i++;

                possible = true;
            }
        }

        return maxm;
    }
};