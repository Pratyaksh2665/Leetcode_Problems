class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        const int mod = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = arr[i] + arr[low] + arr[high];

                if (sum < target) {
                    low++;
                }
                else if (sum > target) {
                    high--;
                }
                else {
                    // arr[low] != arr[high]
                    if (arr[low] != arr[high]) {
                        long long countLow = 1;
                        long long countHigh = 1;

                        while (low + 1 < high && arr[low] == arr[low + 1]) {
                            countLow++;
                            low++;
                        }

                        while (high - 1 > low && arr[high] == arr[high - 1]) {
                            countHigh++;
                            high--;
                        }
                        ans = (ans + countLow * countHigh) % mod;
                        low++;
                        high--;
                    }
                    // arr[low] == arr[high]
                    else {
                        long long cnt = high - low + 1;
                        ans = (ans + (cnt * (cnt - 1)) / 2) % mod;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};