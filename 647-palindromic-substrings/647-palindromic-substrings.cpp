class Solution {
public:
    int countSubstrings(string s) {
        int c=0;
        int n=s.length();
        if(n<=1)
            return n;
        c+=n;
        int i;
        int l,r;
        for(i=1;i<n;i++)
        {
            l=i-1;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                c++;
            }
            
            l=i-1;
            r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                c++;
            }
        }
        return c;
    }
};