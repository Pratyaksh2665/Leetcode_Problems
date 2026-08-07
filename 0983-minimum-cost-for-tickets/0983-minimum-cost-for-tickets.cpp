class Solution {
public:
    int pass(vector<int>& days, vector<int>& costs, int i, int cover,
             vector<vector<int>>& dp) {
        if (i >= days.size())
            return 0;
        if (days[i] <= cover)
            return pass(days, costs, i + 1, cover, dp);

        if (dp[i][cover] != -1)
            return dp[i][cover];

        int one = costs[0] + pass(days, costs, i + 1, days[i], dp);

        int seven = costs[1] + pass(days, costs, i + 1, days[i] + 6, dp);

        int thirty = costs[2] + pass(days, costs, i + 1, days[i] + 29, dp);

        return dp[i][cover] = min(one, min(seven, thirty));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxm = INT_MIN;
        for (auto it : days)
            maxm = max(maxm, it);
        vector<vector<int>> dp(n, vector<int>(maxm + 30, -1));
        return pass(days, costs, 0, 0, dp);
    }
};