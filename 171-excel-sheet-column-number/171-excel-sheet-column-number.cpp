class Solution {
public:
    int titleToNumber(string s)
    {
        int ans=0;
        
        for(char c:s)
        {
            ans=(ans*26)+(c-'A'+1);
        }
        return ans;
    }
    
    /*
    int titleToNumber(string ct) {
        int n=ct.length();
        int i;
        int ans=0;
        for(i=n-1;i>=0;i--)
        {
            ans+=(ct[i]-'A'+1)*pow(26,n-1-i);
        }
        return ans;
    }
    */
};