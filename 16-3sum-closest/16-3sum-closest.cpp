class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        int ans=a[0]+a[1]+a[2];
        int i,n=a.size();
        
        sort(a.begin(),a.end());
        
        for(i=0;i<n-2;i++)
        {
            int l=i+1,r=n-1;
            
            while(l<r)
            {
                int s=a[i]+a[l]+a[r];
                
                if(s==t)
                    return s;
                
                if(abs(s-t)<abs(ans-t))
                    ans=s;
                
                if(s<t)
                    l++;
                else
                    r--;
            }
        }
        
        return ans;
    }
};