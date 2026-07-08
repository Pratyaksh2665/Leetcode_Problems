class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int m = num.size();
        vector<int> sec;
        while (k != 0) {
            sec.push_back(k % 10);
            k /= 10;
        }
        reverse(sec.begin(), sec.end());
        int n = sec.size();

        vector<int> ans;
        int carry = 0;

        int i = m - 1;
        int j = n - 1;

        
        while (i >= 0 && j >= 0) {
            int sum = num[i] + sec[j] + carry;
            carry = sum / 10;
            ans.push_back(sum % 10);
            i--;
            j--;
        }


        while (j >= 0) {
            int sum = sec[j] + carry;
            carry = sum / 10;
            ans.push_back(sum % 10);
            j--;
        }

        
        while (i >= 0) {
            int sum = num[i] + carry;
            carry = sum / 10;
            ans.push_back(sum % 10);
            i--;
        }

        if (carry) ans.push_back(carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
