class Solution {
public:
    int myAtoi(string s)
    {
        int n=s.length();
        int i=0;
        long ans=0;
        int sign=1;
        
        while(s[i]==' ')
            i++;
        
        if(s[i]=='+')
            i++;
        else if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        
        for(i;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=(ans*10)+(s[i]-'0');
            }
            else
                break;
            
            if(sign==1 && ans>=INT_MAX)
                return INT_MAX;
            else if(sign==-1 && -ans<=INT_MIN)
                return INT_MIN;
        }
        
        if(sign==1)
            return ans;
        else
            return -ans;
        
    }
    
    /*
    int myAtoi(string s) {
        int ans=0;
        int n=s.length();
        int i;
        int sign=1;
  
        for(i=0;i<n;i++)
        {
            if(s[i]==' ')
                continue;
            else if(s[i]=='-')
            {
                sign=-1;
                i++;
                break;
            }                
            else if(s[i]=='+')
            {
                sign=1;
                i++;
                break;
            }
            else if(s[i]>='0' && s[i]<='9')
                break;
            else
                break;
                
        }
        
        for(i;i<n;i++)
        {
            if(s[i]==' ')
                break;
            else if(s[i]=='-')
                break;
            else if(s[i]=='+')
                break;
            else if(s[i]>='0' && s[i]<='9')
            {
                if(((long)ans*10+s[i]-'0')>INT_MAX)
                {
                    if(sign==1)
                        return INT_MAX;
                    return INT_MIN;
                }
                ans=ans*10+(s[i]-'0');
                
            }
            else
                break;
        }
        ans*=sign;
        if(ans>INT_MAX)
            ans=INT_MAX;
        else if(ans<INT_MIN)
            ans=INT_MIN;
        
        return ans;
    }
    
    */
};