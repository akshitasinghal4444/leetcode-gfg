class Solution {
public:
    
    int numRescueBoats(vector<int>& a, int lim) {
        
        int i,n=a.size();
        int l=0,r=n-1;
        int ans=0;
        
        sort(a.begin(),a.end());
        
        if(a[0]==lim || lim-a[0]<a[1])
            return n;
        
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
    
    /*
    int numRescueBoats(vector<int>& a, int lim) {
        
        int i,n=a.size();
        int l=0,r=n-1;
        int c=0;
        int ans=0;
        
        sort(a.begin(),a.end());
        
        if(a[0]==lim || lim-a[0]<a[1])
            return n;
        
        while(l<=r)
        {
            if(a[l]+a[r]<=lim)
            {
                if(l!=r)
                    c+=2;
                else
                    c++;
                
                ans++;
                
                l++;
                r--;
            }
            else
                r--;
        }
        
        ans+=n-c;
        return ans;
    }
    */
    
    
};