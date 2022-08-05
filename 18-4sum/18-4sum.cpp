class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        
        int i,j;
        
        i=0,j=n-1;
        for(i=0;i<n-3;i++)
        {
            if(i>0 && a[i]==a[i-1])
                continue;
            
            for(j=i+1;j<n-2;j++)
            {
                if(j!=i+1 && a[j]==a[j-1])
                    continue;
                
                int l=j+1,r=n-1;
                
                while(l<r)
                {
                    long s=(long)a[i]+a[j]+a[l]+a[r];
                    
                    if(s==t)
                    {
                        ans.push_back({a[i],a[j],a[l],a[r]});
                        l++;
                        r--;
                    }
                    else if(s<t)
                        l++;
                    else
                        r--;
                    
                    while(l!=j+1 && l<r && a[l]==a[l-1])
                        l++;
                    
                    while(r!=n-1 && l<r && a[r]==a[r+1])
                        r--;
                }
            }
        }   
        
        return ans;
    }
};