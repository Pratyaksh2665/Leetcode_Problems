class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        int x=0;
        int y=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                st.push(s[i]);
                x++;
            }
            else
            {
                y++;
                if(y>x) return false;
                if(st.top()=='(' && s[i]==')') st.pop();
                else if(st.top()=='{' && s[i]=='}') st.pop();
                else if(st.top()=='[' && s[i]==']') st.pop();
                else return false;
            }
            if(y>x) return false;
        }

        return st.size()==0;

    }
};