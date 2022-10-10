class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.length();
        
        if(n==1)
            return "";
        
        int l=0,r=n-1;
        
        while(l<r)
        {
            if(s[l]!='a')
            {
                s[l]='a';
                return s;
            }
            
            l++;
            r--;
        }
        
        s[n-1]='b';
        
        return s;
    }
};