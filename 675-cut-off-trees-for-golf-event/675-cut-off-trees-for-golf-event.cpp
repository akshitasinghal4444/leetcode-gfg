class Solution {
public:
    
    /*
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
    */
    
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
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        int i,j;
        int m=a.size(),n=a[0].size();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]>1)
                q.push({a[i][j],{i,j}});
            }
        }
        
        int ans=0;
        int cr=0,cc=0;
        
        while(!q.empty())
        {
            int er,ec;
            er=q.top().second.first;
            ec=q.top().second.second;
            q.pop();
            
            int t=min_steps(a,cr,cc,er,ec,m,n);
            
            if(t==INT_MAX)
                return -1;
            
            ans+=t;
            
            cr=er;
            cc=ec;
        }
        
        return ans;
    }
};