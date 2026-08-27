class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        for (int i = 0; i < n; i++) {

            if (freq[target[i] - 'a'] > 0) {
                ans += target[i];
                freq[target[i] - 'a']--;
            }
            else {

                for (int c = target[i] - 'a' + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        ans += char('a' + c);
                        freq[c]--;

                        for (int x = 0; x < 26; x++) {
                            while (freq[x] > 0) {
                                ans += char('a' + x);
                                freq[x]--;
                            }
                        }

                        return ans;
                    }
                }

                break;
            }
        }
        fill(freq.begin(), freq.end(), 0);

        for (char c : s)
            freq[c - 'a']++;

        int i = 0;

        while (i < n && freq[target[i] - 'a'] > 0) {
            freq[target[i] - 'a']--;
            i++;
        }

        for (int pos = i - 1; pos >= 0; pos--) {
            freq[target[pos] - 'a']++;
            for (int c = target[pos] - 'a' + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string result = target.substr(0, pos);

                    result += char('a' + c);
                    freq[c]--;

                    for (int x = 0; x < 26; x++) {
                        while (freq[x] > 0) {
                            result += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};