class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string s=countAndSay(n-1);
        int ns=s.length();
        int i,c=1;
        string ans="";
        
        for(i=1;i<ns;i++)
        {
            if(s[i]==s[i-1])
                c++;
            else
            {
                ans+=to_string(c);
                ans+=s[i-1];
                c=1;
            }
        }
        ans+=to_string(c);
        ans+=s[i-1];
        
        return ans;
    }
    
//     string countAndSay(int n) {
        
//         if(n==1)
//             return "1";
        
//         string s=countAndSay(n-1),ans="";
//         int c=0;
//         char ch=s[0];
            
//         for(char x:s)
//         {
//             if(x==ch)
//                 c++;
//             else
//             {
//                 ans+=(c+'0');
//                 ans+=ch;
                
//                 ch=x;
//                 c=1;
//             }
//         }
//         ans+=(c+'0');
//         ans+=ch;
        
//         return ans;
//     }
};