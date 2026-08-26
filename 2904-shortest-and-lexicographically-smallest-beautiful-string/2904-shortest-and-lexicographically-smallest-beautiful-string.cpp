class Solution { 
public: 
    string shortestBeautifulSubstring(string s, int k) { 
        int n = s.length(); 
        vector<string> v; 
        int i = 0; 
        int j = 0; 
        unordered_map<int,int> mp; 

        while(j < n) 
        { 
            mp[s[j] - '0']++; 

            if(mp[1] < k) 
            { 
                j++; 
            } 
            else 
            { 
                while(mp[1] == k) 
                { 
                    v.push_back(s.substr(i, j - i + 1)); 

                    mp[s[i] - '0']--; 

                    if(mp[s[i] - '0'] == 0) 
                        mp.erase(s[i] - '0'); 

                    i++; 
                }

                j++;
            }
        } 

        if(v.empty())
            return "";

        sort(v.begin(), v.end(), [](string a, string b) {
            if(a.length() != b.length())
                return a.length() < b.length();

            return a < b;
        });

        return v[0]; 
    } 
};