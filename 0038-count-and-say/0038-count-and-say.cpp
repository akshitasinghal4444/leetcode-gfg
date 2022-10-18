class Solution {
public:
    string countAndSay(int n)
    {
        string s="1";
        int i;
        
        while(--n)
        {
            string t="";
            int c=1;
            int ns=s.length();
            
            for(i=1;i<ns;i++)
            {
                if(s[i]==s[i-1])
                    c++;
                else
                {
                    t+=to_string(c);
                    t+=s[i-1];
                    c=1;
                }
            }
            t+=to_string(c);
            t+=s[i-1];
            
            s=t;
        }
        
        return s;
    }
    
    /*
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string s=countAndSay(n-1);
        int ns=s.length();
        int i,c=1;
        string ans="";
        
        for(i=1;i<ns;i++)
        {
            if(s[i]==s[i-1])
                c++;
            else
            {
                ans+=to_string(c);
                ans+=s[i-1];
                c=1;
            }
        }
        ans+=to_string(c);
        ans+=s[i-1];
        
        return ans;
    }
    */
};