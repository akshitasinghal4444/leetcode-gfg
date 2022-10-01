class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        int i,n=a.size();
        vector<vector<int>> ans;
        
        sort(a.begin(),a.end());
        
        for(i=0;i<n-2;i++)
        {
            if(i>0 && a[i]==a[i-1])
                continue;
            
            int l=i+1,r=n-1;
            
            while(l<r)
            {
                int s=a[i]+a[l]+a[r];
                
                if(s==0)
                {
                    ans.push_back({a[i],a[l],a[r]});
                    l++;
                    r--;
                }
                else if(s<0)
                    l++;
                else
                    r--;
                
                while(l>i+1 && l<r && a[l]==a[l-1])
                    l++;
                
                while(r<n-1 && l<r && a[r]==a[r+1])
                    r--;
            }
        }
        
        return ans;
    }
};