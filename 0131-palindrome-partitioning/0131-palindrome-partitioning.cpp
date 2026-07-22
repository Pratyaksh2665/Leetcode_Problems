class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) 
        {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void helper(int start, string &s, vector<string> &curr,vector<vector<string>> &ans)
        {
            if (start == s.size()) 
            {
                ans.push_back(curr);
                return;
            }
        

            for (int end = start; end < s.size(); end++) {
                if (isPalindrome(s, start, end)) {
                    curr.push_back(s.substr(start, end - start + 1));
                    helper(end + 1, s, curr, ans);
                    curr.pop_back();  
                }
            }
        }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0, s, curr, ans);
        return ans;
    }
};