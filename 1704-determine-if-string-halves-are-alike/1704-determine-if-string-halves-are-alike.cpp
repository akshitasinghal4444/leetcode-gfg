class Solution {
public:
    bool halvesAreAlike(string s) {
        int i,j,n=s.length();
        int l=0,r=0;
        unordered_set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        
        for(i=0,j=n-1;i<j;i++,j--)
        {
            if(vowels.find(s[i])!=vowels.end())
                l++;
            
            if(vowels.find(s[j])!=vowels.end())
                r++;
        }
        
        return l==r;
    }
};