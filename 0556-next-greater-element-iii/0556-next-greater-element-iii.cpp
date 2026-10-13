class Solution {
public:
    int nextGreaterElement(int n) {
        int p = n;
        if(n==1) return -1;
        string s = "";
        while(p)
        {
            int x = p%10;
            s+=(x+'0');
            p=p/10;
        }

        reverse(s.begin(),s.end());
        int x = s.length();

        int i = x-2;
        while(i>=0 && s[i]>=s[i+1])
        {
            i--;
        }

        if(i<0) return -1;

        int j = x-1;
        while(s[i]>=s[j])
        {
            j--;
        }

        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());

        long long ans = stoll(s);
        if(ans>INT_MAX) return -1;
        return ans;
    }
};