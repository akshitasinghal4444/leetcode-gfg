class Solution {
public:
    int longestMountain(vector<int>& a)
    {
        int n=a.size();
        int i,j,st=0;
        int ans=0;
        
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                continue;
            else
            {
                if(i!=st+1)
                {
                    j=i;
                    while(j<n && a[j]<a[j-1])
                        j++;
            
                    if(j!=i)
                    ans=max(ans,j-st);
                    
                    st=j-1;
                    i=j-1;
                }
                else
                    st=i;
            }
        }
        return ans;
    }
    
    /*
    int longestMountain(vector<int>& a)
    {
        int n=a.size();
        if(n<3)
            return 0;
        
        int i=1;
        int ans=0,st=0;
        
        for(i=1;i<n-1;i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])
            {
                int j=i-1,c=1;
                while(j>=0 && a[j]<a[j+1])
                {
                    c++;
                    j--;
                }
                
                j=i+1;
                while(j<n && a[j]<a[j-1])
                {
                    c++;
                    j++;
                }
                
                ans=max(ans,c);
                i=j-1;
            }
            else
                continue;
        }
        
        if(ans<3)
            return 0;
        return ans;
    }
    */
    /*
    int longestMountain(vector<int>& a) {
        int l=0;
        int n=a.size();
        
        if(n<3)
            return 0;
        
        int maxl=0;
        bool up=1;
        int i=1;
        while(i<n && a[i]<=a[i-1])
            i++;
        l=i-1;
        for(i;i<n;i++)
        {
            if(up)
            {
                if(a[i]>a[i-1])
                    continue;
                else if(a[i]==a[i-1])
                {
                    l=i;
                }
                else
                {
                    up=0;
                    i--;
                }
            }
            else
            {
                if(a[i]<a[i-1])
                    continue;
                else if(a[i]==a[i-1])
                {
                    maxl=max(maxl,i-l);
                    up=1;
                    l=i;
                    i--;
                }
                else
                {
                    if(a[l]<a[l+1])
                    maxl=max(maxl,i-l);
                    up=1;                    
                    l=i-1;
                    i--;
                }
            }
        }
        if(!up)
        maxl=max(maxl,i-l);
        
        if(maxl>=3)
        return maxl;
        
        return 0;
    }
    */
};