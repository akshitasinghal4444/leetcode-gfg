class Solution {
public:
    int countBinarySubstrings(string s)
    {
        int curr=0,prev=0,ans=0;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(i!=0 && s[i]!=s[i-1])
            {
                ans+=min(curr,prev);
                prev=curr;
                curr=0;
            }
            curr++;
        }
        ans+=min(curr,prev);
        return ans;
    }
    
    
    /*
    int countBinarySubstrings(string s) {
        int z=0,o=0,ans=0;
        bool f=0;
        
        for(char c:s)
        {
            if(c=='0')
            {
                if(f)
                {
                    ans+=min(z,o);
                    f=0;
                    z=0;
                }
                z++;
            }
            else
            {
                if(!f)
                {
                    ans+=min(z,o);
                    f=1;
                    o=0;
                }
                o++;
            }
        }
        ans+=min(z,o);
        return ans;
    }
    */
};