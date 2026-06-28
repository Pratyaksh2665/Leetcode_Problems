class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n=gas.size();
        int deficit=0;
        int balence=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            balence+= gas[i] - cost[i] ;
            if(balence<0)
            {
                deficit += balence;
                start=i+1;
                balence=0;
            }
        }
        if(deficit+balence >= 0) return start;
        
        return -1;
    }
};