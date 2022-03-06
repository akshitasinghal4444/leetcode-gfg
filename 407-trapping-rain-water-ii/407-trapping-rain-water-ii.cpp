class Solution {
public:
    int trapRainWater(vector<vector<int>>& a) {
        int m,n,i,j;
        m=a.size();
        n=a[0].size();
        int water=0;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        
        for(i=0;i<n;i++)
        {
            q.push({a[0][i],0,i});
            q.push({a[m-1][i],m-1,i});
            a[0][i]=-1;
            a[m-1][i]=-1;
        }
        
        for(i=0;i<m;i++)
        {
            q.push({a[i][0],i,0});
            q.push({a[i][n-1],i,n-1});
            a[i][0]=-1;
            a[i][n-1]=-1;
        }
                    
        while(!q.empty())
        {
            int x=q.top()[0];
            i=q.top()[1];
            j=q.top()[2];
            q.pop();
            
            if(j-1>=0 && a[i][j-1]!=-1)
            {
                if(a[i][j-1]<x)
                {
                    water+=(x-a[i][j-1]);
                    a[i][j-1]=x;
                }
                
                q.push({a[i][j-1],i,j-1});
                a[i][j-1]=-1;
            }   
            
            if(j+1<n && a[i][j+1]!=-1)
            {
                if(a[i][j+1]<x)
                {
                    water+=(x-a[i][j+1]);
                    a[i][j+1]=x;
                }
                
                q.push({a[i][j+1],i,j+1});
                a[i][j+1]=-1;
            } 
            
            if(i-1>=0 && a[i-1][j]!=-1)
            {
                if(a[i-1][j]<x)
                {
                    water+=(x-a[i-1][j]);
                    a[i-1][j]=x;
                }
                
                q.push({a[i-1][j],i-1,j});
                a[i-1][j]=-1;
            }  
            
            if(i+1<m && a[i+1][j]!=-1)
            {
                if(a[i+1][j]<x)
                {
                    water+=(x-a[i+1][j]);
                    a[i+1][j]=x;
                }
                
                q.push({a[i+1][j],i+1,j});
                a[i+1][j]=-1;
            }  
        }
        return water;
    }
    
    /*
    int trapRainWater(vector<vector<int>>& a) {
        int m,n,i,j;
        m=a.size();
        n=a[0].size();
        int water=0;
        
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        
        for(i=0;i<n;i++)
        {
            q.push({a[0][i],0,i});
            q.push({a[m-1][i],m-1,i});
            vis[0][i]=1;
            vis[m-1][i]=1;
        }
        
        for(i=0;i<m;i++)
        {
            q.push({a[i][0],i,0});
            q.push({a[i][n-1],i,n-1});
            vis[i][0]=1;
            vis[i][n-1]=1;
        }
                    
        while(!q.empty())
        {
            int x=q.top()[0];
            i=q.top()[1];
            j=q.top()[2];
            q.pop();
            
            if(j-1>=0 && !vis[i][j-1])
            {
                if(a[i][j-1]<x)
                {
                    water+=(x-a[i][j-1]);
                    a[i][j-1]=x;
                }
                
                q.push({a[i][j-1],i,j-1});
                vis[i][j-1]=1;
            }   
            
            if(j+1<n && !vis[i][j+1])
            {
                if(a[i][j+1]<x)
                {
                    water+=(x-a[i][j+1]);
                    a[i][j+1]=x;
                }
                
                q.push({a[i][j+1],i,j+1});
                vis[i][j+1]=1;
            } 
            
            if(i-1>=0 && !vis[i-1][j])
            {
                if(a[i-1][j]<x)
                {
                    water+=(x-a[i-1][j]);
                    a[i-1][j]=x;
                }
                
                q.push({a[i-1][j],i-1,j});
                vis[i-1][j]=1;
            }  
            
            if(i+1<m && !vis[i+1][j])
            {
                if(a[i+1][j]<x)
                {
                    water+=(x-a[i+1][j]);
                    a[i+1][j]=x;
                }
                
                q.push({a[i+1][j],i+1,j});
                vis[i+1][j]=1;
            }  
        }
        return water;
    }
    */
};