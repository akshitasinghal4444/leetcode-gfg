class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns=s.length(),nt=t.length();
        if(ns>nt)
            return 0;
        
        int i=0,j=0;
        
        while(i<ns)
        {
            while(j<nt)
            {
                if(s[i]==t[j])
                {
                    i++;
                    j++;
                    break;
                }
                
                j++;
            }
            
            if(j==nt)
                break;
        }
        
        return i==ns; 
    }
};