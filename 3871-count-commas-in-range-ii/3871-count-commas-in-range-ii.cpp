class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;

        string s=to_string(n);
        int x=s.length();
        vector<long long> last;
        last.push_back(1000LL);
        last.push_back(1000000LL);
        last.push_back(1000000000LL);
        last.push_back(1000000000000LL);
        last.push_back(1000000000000000LL);

        long long total = 0;
        for(int i = 0; i < last.size(); i++) {
            if(n < last[i]) break;

            long long end;
            if(i + 1 < last.size()) end = last[i+1] - 1;
            else end = n;

            long long upper = min(n, end);

            total += (upper - last[i] + 1) * (i + 1);
        }
        return total;
        
    }
};