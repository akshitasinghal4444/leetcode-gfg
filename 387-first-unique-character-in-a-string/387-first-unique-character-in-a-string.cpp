class Solution {
public:
    int firstUniqChar(string s)
    {
        int i,n=s.length();
        int ans=INT_MAX;
        vector<int> f(26,-1);
        
        for(i=0;i<n;i++)
        {
            if(f[s[i]-'a']==-1)
                f[s[i]-'a']=i;
            else
                f[s[i]-'a']=INT_MAX;
        }
        
        for(i=0;i<26;i++)
        {
            if(f[i]!=-1)
                ans=min(ans,f[i]);
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
    
    /*
    int firstUniqChar(string s) {
        int i,n=s.length();
        int f[26]={0};
        
        for(i=0;i<n;i++)
            f[s[i]-'a']++;
            
        for(i=0;i<n;i++)
        {
            if(f[s[i]-'a']==1)
                return i;
        }
        
        return -1;;
    }
    */
};