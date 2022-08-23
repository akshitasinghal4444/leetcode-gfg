class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int ns=s.length(),nt=t.length();
        int i=ns-1,j=nt-1;
        int cs=0,ct=0;
        
        while(i>=0 && j>=0)
        {
            if(s[i]=='#')
            {
                cs++;
                i--;
                continue;
            }
            else if(cs)
            {
                cs--;
                i--;
                continue;
            }         
            
            if(t[j]=='#')
            {
                ct++;
                j--;
                continue;
            }
            else if(ct)
            {
                ct--;
                j--;
                continue;
            }   
            
            if(s[i--]!=t[j--])
                return 0;
        }
        
        while(i>=0)
        {
            if(s[i]=='#')
            {
                cs++;
                i--;
                continue;
            }
            else if(cs)
            {
                cs--;
                i--;
                continue;
            }    
            else
                break;
        }
        
        while(j>=0)
        {
            if(t[j]=='#')
            {
                ct++;
                j--;
                continue;
            }
            else if(ct)
            {
                ct--;
                j--;
                continue;
            }    
            else
                break;
        }
        
        return i==-1 && j==-1;
    }
    
    /*
    bool backspaceCompare(string s, string t) {
        string s1="",s2="";
        
        for(char c:s)
        {
            if(c=='#')
            {
                if(!s1.empty())
                    s1.pop_back();
            }
            else
                s1+=c;
        }
        
        for(char c:t)
        {
            if(c=='#')
            {
                if(!s2.empty())
                    s2.pop_back();
            }
            else
                s2+=c;
        }
        
        return s1==s2;
    }
    */
};