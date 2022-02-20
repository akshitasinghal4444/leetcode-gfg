class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.length();
        int i;
        int mx=1,b=0,e=0;
        
        for(i=0;i<n-1;i++)
        {
            int l=i;
            int r=i+1;
            int len=0;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                len+=2;
            }
            if(len>mx)
            {
                mx=len;
                b=l+1;
                e=r-1;
            }
            
            l=i-1;
            r=i+1;
            len=1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                len+=2;
            }
            if(len>mx)
            {
                mx=len;
                b=l+1;
                e=r-1;
            }            
        }
        
        string ans="";
        for(i=b;i<=e;i++)
            ans+=s[i];
        
        return ans;
    }
    
    /*
    string longestPalindrome(string s)
    {
        int n=s.length();
        if(n==0 || n==1)
            return s;
        int maxl=0,maxr=0,maxlen=1;
        int l=0,r=0,len=1;
        int i;
        for(i=1;i<n;i++)
        {
            l=i-1;
            r=i+1;
            len=1;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    len+=2;
                    l--;
                    r++;
                } 
                else
                    break;
            }
            if(maxlen<len)
            {
                maxlen=len;
                maxl=l+1;
                maxr=r-1;
            }
            
            l=i-1;
            r=i;
            len=0;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    len+=2;
                    l--;
                    r++;
                } 
                else
                    break;
            }
            if(maxlen<len)
            {
                maxlen=len;
                maxl=l+1;
                maxr=r-1;
            }
        }
        // cout<<maxl<<" "<<maxr;
        string ans="";
        while(maxl<=maxr)
            ans+=s[maxl++];
        return ans;
    }
    */

//     string longestPalindrome(string s) {
//         int n=s.length();
//         if(n==0)
//             return "";
//         if(n==1)
//             return s;
//         int i,l,r;
//         int maxl=1,ml=0,mr=0,len;
//         for(i=1;i<n;i++)
//         {
//             l=i-1;
//             r=i+1;
//             len=1;
//             while(l>=0 && r<n && s[l]==s[r])
//             {
//                 len+=2;
//                 l--;
//                 r++;
//             }
//             if(len>maxl)
//             {
//                 maxl=len;
//                 ml=l+1;
//                 mr=r-1;
//             }
//             // cout<<len<<" "<<maxl<<endl;
            
//             l=i-1;
//             r=i;
//             len=0;
//             while(l>=0 && r<n && s[l]==s[r])
//             {
//                 len+=2;
//                 l--;
//                 r++;
//             }
//             if(len>maxl)
//             {
//                 maxl=len;
//                 ml=l+1;
//                 mr=r-1;
//             }
//             // cout<<len<<" "<<maxl<<endl;
//         }
//         string ans="";
//         while(ml<=mr)
//         {
//             ans+=s[ml++];
//         }
//         return ans;
//     }
};