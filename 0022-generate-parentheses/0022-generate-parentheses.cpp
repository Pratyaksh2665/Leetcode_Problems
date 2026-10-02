class Solution {
public:
    void helper(string &s,int l,int r,int n,vector<string>&v)
    {
        if(s.size()==0) 
        {
            s+='(';
            l++;
        }
        if(l==n && r==n) 
        {
            v.push_back(s);
            return;
            
        }
        
        //for (

            if(l<n) 
            {
                s+='(';
                helper(s,l+1,r,n,v);
                s.pop_back();
            }
            // for )
            if(r<l )// hmesha right side wala bracket left se brabr ya km ho skta h
            {
                s+=')';
                helper(s,l,r+1,n,v);
                s.pop_back();
            }



    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string s="";
        helper(s,0,0,n,v);
        return v;

        
    }
};