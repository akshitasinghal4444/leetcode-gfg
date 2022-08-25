class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int m=a.size(),n=a[0].size();
        int l=0,r=n-1,t=0,b=m-1,i;
        
        while(l<=r && t<=b)
        {
            for(i=l;i<=r;i++)
                ans.push_back(a[t][i]);
            t++;
            
            for(i=t;i<=b;i++)
                ans.push_back(a[i][r]);
            r--;
            
            if(r<l || b<t)
                break;
            
            for(i=r;i>=l;i--)
                ans.push_back(a[b][i]);
            b--;
            
            for(i=b;i>=t;i--)
                ans.push_back(a[i][l]);
            l++;
        }
        
        return ans;
    }
};