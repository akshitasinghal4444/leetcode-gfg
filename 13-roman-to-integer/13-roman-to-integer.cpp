class Solution {
public:
    int val(char c)
    {
        switch(c)
        {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
        }
        return -1;
    }
    
    int romanToInt(string s) {
        int ans;
        int n=s.length();
        int i;
        ans=val(s[n-1]);
        
        for(i=n-2;i>=0;i--)
        {
            if(val(s[i])<val(s[i+1]))
                ans-=val(s[i]);
            else
                ans+=val(s[i]);
        }
        
        return ans;
    }
};