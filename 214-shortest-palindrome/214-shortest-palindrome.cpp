class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        
        string str=s+"$";
        string t=s;
        reverse(t.begin(),t.end());
        str+=t;        
        int l=2*n+1;

        int lps[l];
        lps[0]=-1;
        
        int i,j;
        i=1;    j=-1;
        
        while(i<l)
        {
            if(str[i]==str[j+1])
            {
                lps[i]=j+1;
                i++;
                j++;
            }
            else if(j==-1)
            {
                lps[i]=-1;
                i++;
            }
            else
                j=lps[j];
        }
        
        i=n-lps[l-1]-1;

        while(--i>=0)
        {
            t+=t[i];
        }
        return t;
    }
};