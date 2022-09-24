class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,n=s.length();
        int st=0,mlen=1,mf=0;
        int f[256]={0};
        
        for(i=0;i<n;i++)
        {
            f[s[i]]++;
            mf=max(mf,f[s[i]]);
            int len=i-st+1;
            
            if(len-mf<=k)
                mlen=max(mlen,len);
            else
            {
                f[s[st]]--;
                st++;
            }            
        }
        
        return mlen;
    }
    
    /*
    int characterReplacement(string s, int k) {
        int i,n=s.length();
        int st=0,mlen=1,mf=0;
        int f[256]={0};
        
        for(i=0;i<n;i++)
        {
            f[s[i]]++;
            mf=max(mf,f[s[i]]);
            int len=i-st+1;
            
            if(len-mf<=k)
                mlen=max(mlen,len);
            else
            {
                while(st<=i && i-st+1-mf>k)
                {
                    f[s[st]]--;
                    st++;
                }
            }            
        }
        
        return mlen;
    }
    */
};