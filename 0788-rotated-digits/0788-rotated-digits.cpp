class Solution {
public:
    bool check(int n)
    {
        string s=to_string(n);
        bool changed=false;
        for(auto it:s)
        {
            if(it=='3' || it=='4' || it=='7') return false;

            if(it=='2' || it=='5' || it=='6' || it=='9')changed = true;
                
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(check(i))cnt++;
        }

        return cnt;
    }
};