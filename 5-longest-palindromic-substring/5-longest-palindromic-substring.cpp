class Solution {
public:
    void check(int &l,int &r,string &s,int n)
    {
        if(l<0 || r>=n)
        {
            l=0,r=0;
            return;
        }
        
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;
            r++;
        }
        
        l++;
        r--;
    }
    
    string longestPalindrome(string s) {
        int i,n=s.length();
        int st=0,e=0;
        string ans="";
        
        for(i=0;i<n;i++)
        {
            int l=i,r=i+1;
            check(l,r,s,n);
            if(r-l+1>e-st+1)
            {
                st=l;
                e=r;
            }
            
            l=i-1,r=i+1;
            check(l,r,s,n);
            if(r-l+1>e-st+1)
            {
                st=l;
                e=r;
            }
        }
        
        for(i=st;i<=e;i++)
            ans+=s[i];
        
        return ans;
    }
};