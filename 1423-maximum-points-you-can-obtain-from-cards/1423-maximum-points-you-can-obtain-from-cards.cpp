class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int i,j,sum=0,ans;
        
        for(i=0;i<k;i++)
            sum+=a[i];
        
        ans=sum;
        for(i=k-1,j=n-1;i>=0;i--,j--)
        {
            sum-=a[i];
            sum+=a[j];
            ans=max(ans,sum);
            
            // cout<<sum<<" "<<ans<<endl;
        }      
        
        
        return ans;
    }
};