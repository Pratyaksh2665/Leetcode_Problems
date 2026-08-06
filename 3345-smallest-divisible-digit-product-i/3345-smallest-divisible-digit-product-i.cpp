class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= 100; i++) {
            int temp = i;

            int x = temp % 10;
            temp /= 10;

            int y = temp % 10;
            temp /= 10;

            int z = temp % 10;

            if (y == 0 && z == 0) {
                if (x % t == 0)
                    return i;
            } else if (z == 0) {
                if ((x * y) % t == 0)
                    return i;
            } else {
                if ((x * y * z) % t == 0)
                    return i;
            }
        }

        return -1;
    }
};