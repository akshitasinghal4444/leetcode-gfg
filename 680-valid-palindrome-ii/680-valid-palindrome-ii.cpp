class Solution {
public:
    bool validPalindrome(string s,bool f=0)
    {
        int l=0,r=s.length()-1;
        
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
                continue;
            }
            
            if(f==1)
                return 0;
            
            return validPalindrome(s.substr(l,r-l),1) || validPalindrome(s.substr(l+1,r-l),1);
        }
        return 1;
    }
};

