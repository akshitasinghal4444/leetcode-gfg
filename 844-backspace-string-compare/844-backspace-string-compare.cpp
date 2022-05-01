class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int i,j,ns=s.length(),nt=t.length();
        
        i=0,j=0;
        for(i=0;i<ns;i++)
        {
            if(s[i]=='#')
                j=max(0,j-1);
            else
                s[j++]=s[i];
        }
        ns=j;
        
        j=0;
        for(i=0;i<nt;i++)
        {
            if(t[i]=='#')
                j=max(0,j-1);
            else
                t[j++]=t[i];
        }
        nt=j;
        
        if(ns!=nt)
            return 0;
        
        for(i=0;i<ns;i++)
            if(s[i]!=t[i])
                return 0;
        
        return 1;
    }
    
    /*
    bool backspaceCompare(string s, string t) {
        string s1,t1;
        
        for(char c:s)
        {
            if(c=='#')
            {
                if(s1.size())
                    s1.pop_back();
            }
            else
                s1+=c;
        }
        
        for(char c:t)
        {
            if(c=='#')
            {
                if(t1.size())
                    t1.pop_back();
            }
            else
                t1+=c;
        }
        
        return s1==t1;
    }
    */
};