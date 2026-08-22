class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int fin=n;
        while(n>0)
        {
            int x=n%10;
            pro*=x;
            sum+=x;

            n=n/10;
        }

        return (fin%(sum+pro))==0;
    }
};