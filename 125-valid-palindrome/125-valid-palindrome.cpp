class Solution {
public:
    bool isPalindrome(string s)
    {
        int l=0,r=s.length()-1;
        
        while(l<=r)
        {
            if(!isdigit(s[l]) && !isalpha(s[l]))
            {
                l++;
                continue;
            }
                            
            if(!isdigit(s[r]) && !isalpha(s[r]))
            {
                r--;
                continue;
            }   
            
            if(s[l]>='A' && s[l]<='Z')
                s[l]+=32;
            
            if(s[r]>='A' && s[r]<='Z')
                s[r]+=32;
            
            if(s[l]!=s[r])
                return 0;
            else
            {
                l++;
                r--;
            }
        }
        return 1;
    }
    
    /*
    bool isPalindrome(string s) {
        string t="";
        int n=s.length();
        int i,j;
        for(i=0;i<n;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                t+=s[i]+32;
            else if(isdigit(s[i]) || isalpha(s[i]))
                t+=s[i];
        }
        
        n=t.length();
        for(i=0,j=n-1;i<j;i++,j--)
        {
            if(t[i]!=t[j])
                return 0;
        }
        return 1;
    }
    */
};