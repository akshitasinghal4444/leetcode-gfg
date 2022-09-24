class Solution {
public:
    vector<string> ans;
    
    void permute(string s,int n,int in)
    {
        if(in==n)
        {
            ans.push_back(s);
            return;
        }
           
        if(isdigit(s[in]))
        {
            permute(s,n,in+1);
            return;
        }
        
        s[in]=tolower(s[in]);
        permute(s,n,in+1);
        
        s[in]=toupper(s[in]);
        permute(s,n,in+1);
    }
    
    vector<string> letterCasePermutation(string s) {
        permute(s,s.length(),0);
        return ans;
    }
};