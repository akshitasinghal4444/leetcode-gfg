class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
            return "1";
        
        string s=countAndSay(n-1),ans="";
        int c=0;
        char ch=s[0];
            
        for(char x:s)
        {
            if(x==ch)
                c++;
            else
            {
                ans+=(c+'0');
                ans+=ch;
                
                ch=x;
                c=1;
            }
        }
        ans+=(c+'0');
        ans+=ch;
        
        return ans;
    }
};