class Solution {
public:
    long long smallestNumber(long long n) {
        string s=to_string(abs(n));
        
        if(n<0)
            sort(s.begin(),s.end(),greater<char>());
        else
            sort(s.begin(),s.end());
        
        
        if(n>0)
        {
            int i=0;
            while(i<s.length() && s[i]=='0')
                i++;
            
            if(s[0]=='0')
            {
                s[0]=s[i];
                s[i]='0';
            }
        }
        
        if(n>=0)
        return stoll(s);
        
        return -stoll(s);       
    }
};