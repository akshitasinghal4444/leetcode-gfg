class Solution {
public:
    int min_steps(vector<vector<int>>& a,int sr,int sc,int er,int ec,int m,int n)
    {
        
        if(sr==er && sc==ec)
            return 0;
        
        if(a[sr][sc]==0)
            return INT_MAX;
        
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int ans=0;
        
        while(!q.empty())
        {
            int s=q.size();
            ans++;
            
            while(s--)
            {
                sr=q.front().first;
                sc=q.front().second;
                q.pop();
                
                if(sr-1>=0 && a[sr-1][sc]>0 && !vis[sr-1][sc])
                {
                    if(sr-1==er && sc==ec)
                        return ans;
                    
                    vis[sr-1][sc]=1;
                    q.push({sr-1,sc});
                }
                
                if(sc-1>=0 && a[sr][sc-1]>0 && !vis[sr][sc-1])
                {
                    if(sr==er && sc-1==ec)
                        return ans;
                    
                    vis[sr][sc-1]=1;
                    q.push({sr,sc-1});
                }
                
                if(sr+1<m && a[sr+1][sc]>0 && !vis[sr+1][sc])
                {
                    if(sr+1==er && sc==ec)
                        return ans;
                    
                    vis[sr+1][sc]=1;
                    q.push({sr+1,sc});
                }
                
                if(sc+1<n && a[sr][sc+1]>0 && !vis[sr][sc+1])
                {
                    if(sr==er && sc+1==ec)
                        return ans;
                    
                    vis[sr][sc+1]=1;
                    q.push({sr,sc+1});
                }
            }
        }
        
        return INT_MAX;
    }
    
    
    int cutOffTree(vector<vector<int>>& a) {
        vector<pair<int,pair<int,int>>> v;
        int i,j;
        int m=a.size(),n=a[0].size();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]>1)
                v.push_back({a[i][j],{i,j}});
            }
        }
        
        sort(v.begin(),v.end());
        
        int ans=0;
        int l=v.size();
        int cr=0,cc=0;
        
        for(i=0;i<l;i++)
        {
            int t=min_steps(a,cr,cc,v[i].second.first,v[i].second.second,m,n);
            
            if(t==INT_MAX)
                return -1;
            
            ans+=t;
            
            cr=v[i].second.first;
            cc=v[i].second.second;
        }
        
        return ans;
    }
    
    /*
    int min_steps(vector<vector<int>>& a,int i,int j,int x,int y,int m,int n)
    {
        
        if(i==x && j==y)
            return 0;
        
        if(a[i][j]==0)
            return INT_MAX;
        
        int temp=a[i][j];
        a[i][j]=-1;
        
        int ans=INT_MAX;
        
        if(i-1>=0 && a[i-1][j]>0)
        {
            int t=min_steps(a,i-1,j,x,y,m,n);
            if(t!=INT_MAX)
                ans=min(ans,1+t);
        }

        
        if(j-1>=0 && a[i][j-1]>0)
        {
            int t=min_steps(a,i,j-1,x,y,m,n);
            if(t!=INT_MAX)
                ans=min(ans,1+t);
        }
        
        if(i+1<m && a[i+1][j]>0)
        {
            int t=min_steps(a,i+1,j,x,y,m,n);
            if(t!=INT_MAX)
                ans=min(ans,1+t);
        }
        
        if(j+1<n && a[i][j+1]>0)
        {
            int t=min_steps(a,i,j+1,x,y,m,n);
            if(t!=INT_MAX)
                ans=min(ans,1+t);
        }
        
        a[i][j]=temp;
        return ans;
    }
    
    int dfs(vector<vector<int>>& a,int i,int j,vector<pair<int,pair<int,int>>> &v,int m,int n)
    {
        if(v.empty())
            return 0;
        
        int x=v.back().second.first;
        int y=v.back().second.second;
        v.pop_back();
                
        int ans;
        ans=min_steps(a,i,j,x,y,m,n);
        
        if(ans==INT_MAX)
            return -1;
        
        int t=dfs(a,x,y,v,m,n);
        if(t!=-1)
        return ans+t;
        
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& a) {
        vector<pair<int,pair<int,int>>> v;
        int i,j;
        int m=a.size(),n=a[0].size();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]>1)
                v.push_back({a[i][j],{i,j}});
            }
        }
        
        sort(v.begin(),v.end(),greater<pair<int,pair<int,int>>>());
        
        return dfs(a,0,0,v,m,n);
    }
    */
};