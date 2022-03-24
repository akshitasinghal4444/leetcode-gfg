class Solution {
public:
    
    int numRescueBoats(vector<int>& a, int lim) {
        
        int l=0,r=a.size()-1;
        int ans=0;
        
        sort(a.begin(),a.end());
        
        if(a[0]==lim || lim-a[0]<a[1])
            return a.size();
        
        while(l<=r)
        {
            if(a[l]+a[r]<=lim)
            {
                l++;
                r--;
            }
            else
                r--;
            
            ans++;
        }
        
        return ans;
    }
    
};