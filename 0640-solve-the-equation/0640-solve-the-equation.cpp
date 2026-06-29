class Solution {
public:
    string solveEquation(string s) {
        int n = s.length();

        int t1 = 0; // left x
        int t2 = 0; // left constants
        int t3 = 0; // right x
        int t4 = 0; // right constants

        bool flag = false;

        for (int i = 0; i < n; i++) {

            if (s[i] == '=') {
                flag = true;
                continue;
            }

            int sign = 1;
            if (s[i] == '+') {
                sign = 1;
                i++;
            }
            else if (s[i] == '-') {
                sign = -1;
                i++;
            }

            string t = "";

            while (i < n && s[i] != '+' && s[i] != '-' && s[i] != '=') {
                t += s[i];
                i++;
            }

            i--;

            if (t.back() == 'x') {
                t.pop_back();

                int p;

                if (t == "")
                    p = 1;
                else
                    p = stoi(t);

                p *= sign;

                if (!flag)
                    t1 += p;
                else
                    t3 += p;
            }
            else {

                int p = stoi(t);
                p *= sign;

                if (!flag)
                    t2 += p;
                else
                    t4 += p;
            }
        }

        int coeff = t1 - t3;
        int constant = t4 - t2;

        if (coeff == 0 && constant == 0)
            return "Infinite solutions";

        if (coeff == 0)
            return "No solution";

        return "x=" + to_string(constant / coeff);
    }
};