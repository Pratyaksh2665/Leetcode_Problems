class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> pairs(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;

            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            pairs[g] = cnt * (cnt - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                pairs[g] -= pairs[multiple];
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + pairs[i];

        vector<int> ans;
        for (long long k : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), k + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};