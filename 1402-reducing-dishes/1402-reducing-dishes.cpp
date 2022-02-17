class Solution {
public:
    int maxSatisfaction(vector<int>& a)
    {
        int n=a.size();
        sort(a.begin(),a.end());
        
        int s=0,ans=0;
        int i,j,in=-1;
        
        for(i=0,j=1;i<n;i++)
        {
            if(a[i]<0)
            {
                in=i;
                continue;
            }
                          
            s+=a[i];
            ans+=(j*a[i]);
            j++;
        }
        
        for(i=in;i>=0;i--)
        {
            s+=a[i];
            if(ans+s<ans)
                break;
            ans+=s;
        }
        
        return ans;
    }
    
    /*
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(),a.end());
        int i,j,n,s=0;
        n=a.size();
        
        for(i=n-1;i>=0;i--)
        {
            if(a[i]<0 && s<-a[i])
                break;
            s+=a[i];
        }
        
        s=0;
        j=1;
        for(i=i+1;i<n;i++,j++)
            s+=(a[i]*j);
        
        return s;
        
    }
    */
};