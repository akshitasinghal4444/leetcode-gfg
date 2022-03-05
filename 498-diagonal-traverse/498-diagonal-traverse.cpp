class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a)
    {
        map<int,vector<int>> mp;
        int m,n,i,j;
        m=a.size();
        n=a[0].size();
        vector<int> ans;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                mp[i+j].push_back(a[i][j]);
            }
        }
        
        for(auto [s,v]:mp)
        {
            if(s%2==0)
                reverse(v.begin(),v.end());
            
            for(auto x:v)
            {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
    
    /*
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        int m,n,i,j;
        
        m=a.size();
        n=a[0].size();
        i=0,j=-1;
        bool dir=1;
        vector<int> ans;
        
        while(i<m || j<n)
        {
            if(dir==1)
                j++;
            else
                i++;
            
            if(i>=m)
            {
                i--;
                j++;
            }
            else if(j>=n)
            {
                j--;
                i++;
            }
                
            while(i<m && j<n && i>=0 && j>=0)
            {
                ans.push_back(a[i][j]);
                
                if(dir)
                {
                    i--;
                    j++;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            
            dir=!dir;
        }
        return ans;
    }
    */
};