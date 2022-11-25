class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int i,n=s.length();
        int ans=0;
        char c=s[0];
        int mx=t[0],sum=t[0];
        
        for(i=1;i<n;i++)
        {
            if(s[i]==c)
            {
                mx=max(mx,t[i]);
                sum+=t[i];
            }
            else
            {
                ans+=(sum-mx);
                sum=mx=t[i];
                c=s[i];
            }
            
            // cout<<i<<" "<<sum<<" "<<mx<<endl;
        }
        ans+=(sum-mx);
        
        return ans;
    }
};