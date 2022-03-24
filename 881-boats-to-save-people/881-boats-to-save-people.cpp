class Solution {
public:
    int numRescueBoats(vector<int>& a, int lim) {
        
        int i,n=a.size();
        int l=0,r=n-1;
        unordered_set<int> vis;
        
        sort(a.begin(),a.end());
        
        if(a[0]==lim || lim-a[0]<a[1])
            return n;
       
        int ans=0;
        while(l<=r)
        {
            if(a[l]+a[r]<=lim)
            {
                vis.insert(l);
                vis.insert(r);
                ans++;
                
                l++;
                r--;
            }
            else
                r--;
        }
        
        ans+=n-vis.size();
        return ans;
    }
};