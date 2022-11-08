class Solution {
public:
    string makeGood(string s) {
        int i,n=s.length();
        string ans="";
        
        for(i=0;i<n;i++)
        {
            if(!ans.empty() && (ans.back()-'a'==s[i]-'A' || ans.back()-'A'==s[i]-'a'))
                ans.pop_back();
            else
                ans+=s[i];
        }
        
        return ans;
    }
};