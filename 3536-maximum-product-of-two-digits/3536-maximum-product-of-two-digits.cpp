class Solution {
public:
    int maxProduct(int x) {
        string s=to_string(x);
        sort(s.begin(),s.end());
        int  n=s.length();
        long long pro;
        pro=(s[n-2]-'0')*(s[n-1]-'0');

        return (int)pro;
    }
};