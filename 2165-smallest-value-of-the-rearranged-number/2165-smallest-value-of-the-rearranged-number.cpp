class Solution {
public:
    long long smallestNumber(long long n)
    {
        int f[10]={0};
        long long ans=0;
        bool s=0;
        
        if(n<0)
        {
            s=1;
            n=-n;
        }
        
        while(n>0)
        {
            f[n%10]++;
            n=n/10;
        }
        
        if(!s)
        {
            int i=1;
        
            while(i<=9)
            {
                if(f[i]>0)
                {
                    ans=(ans*10)+i;
                    f[i]--;
                    if(f[0]>0)
                        i=0;
                }
                else
                    i++;
            }
        }
        else
        {
            int i=9;
            
            while(i>=0)
            {
                if(f[i]>0)
                {
                    ans=(ans*10)+i;
                    f[i]--;
                }
                else
                    i--;
            }
            ans=-ans;
        }

        return ans;
    }
    
    /*
    long long smallestNumber(long long n) {
        string s=to_string(abs(n));
        
        if(n<0)
            sort(s.begin(),s.end(),greater<char>());
        else
            sort(s.begin(),s.end());
        
        
        if(n>0 && s[0]=='0')
        {
            int i=0;
            while(i<s.length() && s[i]=='0')
                i++;
    
            s[0]=s[i];
            s[i]='0';
            
        }
        
        if(n>=0)
        return stoll(s);
        
        return -stoll(s);       
    }
    */
};