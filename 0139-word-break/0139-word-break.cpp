class Solution {
public:

    class Node {
    public:
        Node* children[26];
        bool eow;

        Node() {
            for (int i = 0; i < 26; i++)
                children[i] = NULL;

            eow = false;
        }
    };

    Node* root;
    vector<int> dp;

    Solution() {
        root = new Node();
    }

    void insert(string word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->children[idx] == NULL) {
                node->children[idx] = new Node();
            }

            node = node->children[idx];
        }

        node->eow = true;
    }

    bool helper(string& s, int start) {

        if (start == s.length())
            return true;

        if (dp[start] != -1)
            return dp[start];

        Node* node = root;

        for (int i = start; i < s.length(); i++) {

            int idx = s[i] - 'a';

            if (node->children[idx] == NULL)
                break;

            node = node->children[idx];

            if (node->eow) {

                if (helper(s, i + 1))
                    return dp[start] = 1;
            }
        }

        return dp[start] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (string word : wordDict) {
            insert(word);
        }

        dp.assign(s.length(), -1);

        return helper(s, 0);
    }
};