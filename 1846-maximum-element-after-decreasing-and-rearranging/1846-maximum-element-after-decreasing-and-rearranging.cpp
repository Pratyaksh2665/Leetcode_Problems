class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        int n = arr.size();

        sort(arr.begin(), arr.end());
        int maxm = 1;
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            int x = arr[i];
            int y = arr[i - 1];
            if (abs(x - y) <= 1)
            {
                maxm = max(maxm, arr[i]);
                continue;
            }
                
            else {
                arr[i] = y + 1;
                maxm = max(maxm, arr[i]);
            }

            
        }

        return maxm;
    }
};