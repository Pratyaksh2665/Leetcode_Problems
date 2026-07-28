class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        sort(s.begin(), s.end());

        string ans(s.size(), ' ');
        int left = 0, right = s.size()-1;

        for (int i = 0; i < s.size(); ) {
            if (i + 1 < s.size() && s[i] == s[i+1]) {
                ans[left++] = s[i];
                ans[right--] = s[i];
                i += 2;
            } else {
                ans[s.size()/2] = s[i];
                i++;
            }
        }
        return ans;
    }
};