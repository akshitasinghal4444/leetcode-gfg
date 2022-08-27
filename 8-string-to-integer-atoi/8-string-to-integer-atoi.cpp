class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        bool neg=0;
        int i=0,n=s.length();
        
        while(i<n && s[i]==' ')
            i++;
        
        if(s[i]=='+')
            i++;
        else if(s[i]=='-')
        {
            neg=1;
            i++;
        }
        
        for(i;i<n;i++)
        {
            if(s[i]<'0' || s[i]>'9')
                break;
            
            ans=(ans*10)+(s[i]-'0');
            
            if(ans>INT_MAX)
            {
                if(neg)
                    return INT_MIN;
                return INT_MAX;
            }
            else if(ans==INT_MAX && !neg)
                return INT_MAX;
        }
        
        if(neg)
            return -ans;
        return ans;
    }
};