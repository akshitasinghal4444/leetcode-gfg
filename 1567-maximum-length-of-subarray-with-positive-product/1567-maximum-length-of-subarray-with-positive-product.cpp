class Solution {
public:
    int getMaxLen(vector<int>& a)
    {
        int i,n=a.size();
        int st=0,neg=0,ans=0,x,last=-1,first=-1;
        
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                if(neg%2==0)
                    x=i-st;  
                else        
                    x=max(last-st,i-first-1);
                
                ans=max(ans,x);
                neg=0;
                st=i+1;
            }
            else if(a[i]<0)
            {
                neg++;
                if(first<st)
                    first=i;
                last=i;
            }
                
        }
        
        if(neg%2==0)
            x=i-st;  
        else        
            x=max(last-st,i-first-1);
                     
        ans=max(ans,x);
        
        return ans;
    }
    
    /*
    int getMaxLen(vector<int>& a) {
        int n=a.size();
        int l=0,r=n-1,lst=0,rst=n-1;
        int lp=1,rp=1;
        int ans=0;
        
        while(l<n)
        {
            if(a[l]==0)
            {
                lp=1;
                lst=l+1;
            }
            else
            {
                lp*=a[l]>0?1:-1;
                
                if(lp>0)
                ans=max(ans,l-lst+1);
            }
            
            if(a[r]==0)
            {
                rp=1;
                rst=r-1;
            }
            else
            {
                rp*=a[r]>0?1:-1;
                
                if(rp>0)
                ans=max(ans,rst-r+1);
            }
            
            l++;
            r--;
        }
        
        return ans;
    }
    */
};