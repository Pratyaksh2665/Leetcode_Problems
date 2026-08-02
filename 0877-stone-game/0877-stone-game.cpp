class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int i=0;
        int j=n-1;
        bool alice=true;
        int sum1=0;
        int sum2=0;
        while(i<j)
        {
            if(alice)
            {
                if(piles[i]>=piles[j])
                {
                    sum1+=piles[i];
                    i++;
                }
                else
                {
                    sum1+=piles[j];
                    j--;
                }
            }
            else
            {
                if(piles[i]<piles[j])
                {
                    sum2+=piles[i];
                    i++;
                }
                else
                {
                    sum2+=piles[j];
                    j--;
                }
            }
        }
        return sum1>=sum2;
    }
};