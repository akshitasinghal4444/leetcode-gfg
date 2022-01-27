class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPalindrome(int l,int r,string s)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return 0;
            l++;
            r--;
        }
        return 1;
    }
    
    void helper(string s,int n,int st,vector<string> t)
    {
        if(st==n)
            ans.push_back(t);
        int i;
        for(i=st;i<n;i++)
        {
            if(isPalindrome(st,i,s))
            {
                t.push_back(s.substr(st,i-st+1));
                helper(s,n,i+1,t);
                t.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s)
    {
        int n=s.size();
        helper(s,n,0,{});
        return ans;
    }
};