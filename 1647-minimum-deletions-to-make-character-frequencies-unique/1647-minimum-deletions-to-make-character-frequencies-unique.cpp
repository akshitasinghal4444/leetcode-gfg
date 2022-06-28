class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> m;
        int f[26]={0};
        int i, n=s.length();
        int ans=0;
        
        for(i=0;i<n;i++)
            f[s[i]-'a']++;
        
        for(i=0;i<26;i++)
        {
            if(m.find(f[i])==m.end())
            {
                m.insert(f[i]);
                continue;
            }
            
            while(m.find(f[i])!=m.end() && f[i]>0)
            {
                ans++;
                f[i]--;
            }
            
            if(f[i]>0)
                m.insert(f[i]);
            // cout<<i<<" "<<f[i]<<" "<<ans<<endl;
        }
        
        return ans;
    }
};