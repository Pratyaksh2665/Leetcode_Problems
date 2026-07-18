class Solution {
public:
    int gcd(int a,int b)
    {
        if(a == 0) return b;
        return gcd(b%a , a);
    }
    string gcdOfStrings(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();

        if(str1+str2 != str2+str1) return  "";
        int n=gcd(n2,n1);
        string ans="";
        for(int i=0;i<n;i++)
        {
            ans+=str2[i];
        } 
        return ans;
    }
};