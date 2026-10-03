class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {

        queue<pair<int,int>> q;
        q.push({start, 0});

        vector<int> steps(1001, 1e9);
        steps[start] = 0;

        while (!q.empty()) {
            auto [node, stp] = q.front();
            q.pop();

            for (int x : nums) {

                int next[3] = {
                    node + x,
                    node - x,
                    node ^ x
                };

                for (int num : next) {

                    if (num == goal)    
                        return stp + 1;

                    if (num < 0 || num > 1000)
                        continue;

                    if (stp + 1 < steps[num]) {
                        steps[num] = stp + 1;
                        q.push({num, stp + 1});
                    }
                }
            }
        }
        return -1;
    }
};
