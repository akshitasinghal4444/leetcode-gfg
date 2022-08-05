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
            while(i>0 && i<n-3 && a[i]==a[i-1])
                i++;
            
            for(j=i+1;j<n-2;j++)
            {
                while(j!=i+1 && j<n-2 && a[j]==a[j-1])
                    j++;
                
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