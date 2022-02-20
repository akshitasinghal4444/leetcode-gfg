class Solution {
public:
    string reverseWords(string s)
    {
        int n=s.length();
        int i;
        string ans="";
        string t="";
        for(i=n-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                if(t.size()>0)
                {
                    reverse(t.begin(),t.end());
                    ans+=t;
                    ans+=' ';
                    t="";
                }
            }
            else
            {
                t+=s[i];
            }
        }
        
        if(t.size()>0)
        {
            reverse(t.begin(),t.end());
            ans+=t;
            t="";
        }
        
        if(ans.back()==' ')
            ans.pop_back();
        
        return ans;
    }
    
    /*
    string reverseWords(string s) {
        string ans="";
        string t="";
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
                t+=s[i];
            else if(t.size())
            {
                reverse(t.begin(),t.end());
                ans+=t;
                ans+=' ';
                t="";
            }
        }
        if(t.size())
        {
            reverse(t.begin(),t.end());
                ans+=t;
        }
        if(*ans.rbegin()==' ')
            ans.pop_back();
        return ans;
    }
    */
};