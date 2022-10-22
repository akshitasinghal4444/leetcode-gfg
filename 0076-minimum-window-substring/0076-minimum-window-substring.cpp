class Solution {
public:
    string minWindow(string s, string t) {
        int ns=s.length(),nt=t.length();
        int i,j=0,c=0;
        int st=0,len=INT_MAX;
        int f[256]={0};
        
        for(i=0;i<nt;i++)
            f[t[i]]++;
        
        for(i=0;i<ns;i++)
        {
            if(--f[s[i]]>=0)
                c++;
            
            while(c==nt && j<=i)
            {
                if(len>i-j+1)
                {
                    len=i-j+1;
                    st=j;
                }
                
                if(++f[s[j]]>0)
                    c--;
                
                j++;
            }
        }
        
        if(len!=INT_MAX)
        return s.substr(st,len);
        
        return "";
    }
};