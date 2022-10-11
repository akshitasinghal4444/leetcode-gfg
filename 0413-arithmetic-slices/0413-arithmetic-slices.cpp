class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int i,n=a.size();
        
        if(n<3)
            return 0;
        
        int l=0,ans=0,d=a[1]-a[0];
        
        for(i=2;i<n;i++)
        {
            if(a[i]-a[i-1]==d)
                l++;
            else
            {
                l=0;
                d=a[i]-a[i-1];
            }
            
            ans+=l;
        }
        
        return ans;
    }
    
    /*
    int numberOfArithmeticSlices(vector<int>& a) {
        int i,n=a.size();
        
        if(n<3)
            return 0;
        
        int st=0,ans=0,d=a[1]-a[0];
        
        for(i=2;i<n;i++)
        {
            if(a[i]-a[i-1]==d)
                continue;
            
            int l=i-st;
            st=i-1;
            d=a[i]-a[i-1];
            
            if(l>=3)
            ans+=((l-2)*l-l*(l-1)/2+1);
        }
        
        int l=i-st;
        if(l>=3)
            ans+=((l-2)*l-l*(l-1)/2+1);
        
        return ans;
    }
    */
};