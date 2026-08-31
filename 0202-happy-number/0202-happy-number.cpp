class Solution {
public:
    int next(int n)
    {
        int sum=0;
        while(n>0)
        {
            int d=n%10;
            sum+=d*d;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // unordered_set<int>x;
        // while(n!=1)
        // {
        //     if(x.find(n)!=x.end()) return false;//loop mil gya to 1 nhi aa skta h ab
        //     x.insert(n);
        //     n=next(n);
        // }
        // return true;

        //m2 possible for it is 2 pointer as in linked list to detect a cycle 
        int slow = n;
        int fast = next(n);

        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
            if(slow==1 || fast==1) return true;
        }
        return fast == 1;
        
    }
};