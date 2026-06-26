class Solution {
public:
    bool isValidSerialization(string preorder) {

        stack<string> st;

        string token = "";

        for (int i = 0; i <= preorder.size(); i++) {

            if (i == preorder.size() || preorder[i] == ',') {

                st.push(token);

                // Reduce while top is # # number
                while (st.size() >= 3) {

                    string first = st.top(); st.pop();
                    string second = st.top(); st.pop();
                    string third = st.top(); st.pop();

                    if (first == "#" && second == "#" && third != "#") {
                        st.push("#");
                    }
                    else {
                        st.push(third);
                        st.push(second);
                        st.push(first);
                        break;
                    }
                }

                token = "";
            }
            else {
                token += preorder[i];
            }
        }

        return st.size() == 1 && st.top() == "#";
    }
};