class Solution {
public:
    int findMinDifference(vector<string>& time) {
        int n = time.size();
        vector<int> v;

        for (int i = 0; i < n; i++) {
            string s = time[i];

            int h = stoi(s.substr(0, 2));
            int m = stoi(s.substr(3, 2));

            v.push_back(h * 60 + m);
        }
        sort(v.begin(), v.end());

        int minm = INT_MAX;

        for (int i = 1; i < n; i++)minm = min(minm, v[i] - v[i - 1]);

        minm = min(minm, 1440 - v.back() + v[0]);
        return minm;
    }
};