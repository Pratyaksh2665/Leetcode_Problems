class Solution {
public:
    int gcd(int a,int b)
    {
        int maxm=1;
        for(int i=2;i*i<=a;i++)
        {
            if(b%i==0) maxm=max(maxm,i);
        }
        return maxm;
    }
    int gcdOfOddEvenSums(int n) {
        int count=0;
        int i=1;
        int j=2;
        int sum1=0;
        int sum2=0;
        while(count<n)
        {
            sum1+=i;
            sum2+=j;
            count++;
            i+=2;
            j+=2;
        }

        return gcd(sum1,sum2);
           
    }
};