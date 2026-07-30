class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int sum=0;
        int q=n/8;
        int cnt=1;
        int rem=n%8;
        while(q>0)
        {
            sum+=(8*cnt);
            cnt++;
            q--;
        }
        sum+=(rem*cnt);
        return sum; 
    }
};