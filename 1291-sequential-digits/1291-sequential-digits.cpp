class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int>ans;
        for(int i=0;i<9;i++)
        {
            for(int j=i+1;j<9;j++)
            {
                string t=s.substr(i,j-i+1);
                int x = stoi(t);

                if(x>=low && x<=high ) ans.push_back(x);
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};