class Solution {
public:
    string minWindow(string s, string t) {
        int b=0,mn=INT_MAX,c=0,in=-1;
        int ns=s.length(),nt=t.length();
        unordered_map<char,int> m1,m2;
        int i;
        
        for(i=0;i<nt;i++)
            m1[t[i]]++;
        
        
        for(i=0;i<ns;i++)
        {
            if(c<nt)
            {
                m2[s[i]]++;
                
                if(m1.find(s[i])!=m1.end() && m2[s[i]]<=m1[s[i]])
                    c++;
            }
            
            while(c==nt && b<=i)
            {
                if(i-b+1<mn)
                {
                    mn=i-b+1;
                    in=b;
                }
                m2[s[b]]--;
                
                if(m1.find(s[b])!=m1.end() && m2[s[b]]<m1[s[b]])
                    c--;
                
                b++;
            }
        }
        
        if(mn==INT_MAX)
            return "";
        
        return s.substr(in,mn);
    }
};