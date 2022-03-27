class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& a, int k)
    {
        vector<int> ans;
        int m=a.size(),n=a[0].size();
        int i,j;
        
        for(i=0;i<m;i++)
            a[i].push_back(i);
        
        sort(a.begin(),a.end());
        
        for(i=0;i<k;i++)
            ans.push_back(a[i][n]);
        
        return ans;
    }
    
    /*
    vector<int> kWeakestRows(vector<vector<int>>& a, int k) {
        map<int,vector<int>> mp;
        vector<int> ans;
        int m=a.size(),n=a[0].size();
        int i,j;
        
        for(i=0;i<m;i++)
        {
            int c=0;
            for(j=0;j<n;j++)
            {
                if(a[i][j]==0)
                    break;
                c++;
            }
            
            mp[c].push_back(i);
        }
        
        for(auto it:mp)
        {
            if(k==0)
                break;
            
            sort(it.second.begin(),it.second.end());
            
            int l=it.second.size();
            
            for(i=0;i<l;i++)
            {
                if(k<=0)
                    break;
                k--;
                ans.push_back(it.second[i]);
            }
        }
        
        return ans;
    }
    */
};