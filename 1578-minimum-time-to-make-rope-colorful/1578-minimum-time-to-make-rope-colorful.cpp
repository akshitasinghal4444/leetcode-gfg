class Solution {
public:
    int minCost(string s, vector<int>& a) {
        int i,n=s.length();
        int ans=0;
        
        for(i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
                continue;
            
            int t=a[i-1],total=a[i-1];
            while(i<n && s[i]==s[i-1])
            {
                total+=a[i];
                t=max(t,a[i++]);
            }
            
            ans+=total-t;
        }
        
        return ans;
    }
};