class Solution {
public:
    string minWindow(string s, string t) {
        int ns=s.length(),nt=t.length();
        int f[256]={0};
        int i,j=-1;
        int st=0;
        int len=INT_MAX,c=0;
        
        for(i=0;i<nt;i++)
            f[t[i]]++;
        
        for(i=0;i<ns;i++)
        {
            f[s[i]]--;
            
            if(f[s[i]]>=0)
            c++;
            
            while(c==nt && st<=i)
            {
                if(i-st+1<len)
                {
                    len=i-st+1;
                    j=st;
                }
                
                f[s[st]]++;
                
                if(f[s[st]]>0)
                    c--;
                
                st++;
            }
        }
        
        if(len==INT_MAX)
            return "";
        
        return s.substr(j,len);
    }
};