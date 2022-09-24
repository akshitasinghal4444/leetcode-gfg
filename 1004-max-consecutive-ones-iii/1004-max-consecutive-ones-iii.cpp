class Solution {
public:
    int longestOnes(vector<int>& a, int k)
    {
        int l,r,n=a.size();
        int z=0,ans=0;
        
        for(l=0,r=0;r<n;r++)
        {
            if(a[r]==0)
                z++;
            
            if(z>k)
            {
                if(a[l]==0)
                    z--;
                l++;
            }
            else
                ans=max(ans,r-l+1);
        }
        
        return ans;
    }
    
    /*
    int longestOnes(vector<int>& a, int k) {
        int i,n=a.size();
        int st=0,c=0,ans=0,f=0;
        
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
                f++;
            
            int len=i-st+1;
            
            if(len-f<=k)
                ans=max(ans,len);
            else
            {
                if(a[st]==1)
                    f--;
                
                st++;
            }
        }
        
        return ans;
    }
    */
};
