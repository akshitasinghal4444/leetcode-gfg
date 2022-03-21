class Solution {
public:
    int find(int x,vector<vector<int>>& a,int n)
    {
        int cr,cc;
        x--;
        cr=n-x/n-1;
        cc=x%n;
        
        bool rev=0;
        if(n%2==0)
            rev=(cr%2==0);
        else
            rev=(cr%2!=0);
        
        if(rev)
            cc=n-cc-1;
        
        if(a[cr][cc]!=-1)
            return a[cr][cc];
        else
            return x+1;
    }
    
    int snakesAndLadders(vector<vector<int>>& a)
    {
        int n=a.size();
        if(n==1)
            return 0;
        
        unordered_set<int> vis;
        queue<int> q;
        q.push(1);
        vis.insert(1);
        
        int ans=0;
        
        
        while(!q.empty())
        {
            int s=q.size();
            ans++;
            
            while(s--)
            {
                int beg=q.front();
                q.pop();
                
                for(int i=1;i<7 && beg+i<=n*n;i++)
                {
                    int end=find(beg+i,a,n);
                    if(end==n*n)
                        return ans;
                    
                    if(vis.find(end)==vis.end())
                    {
                        q.push(end);
                        vis.insert(end);
                    }
                }
            }
        }
        
        return -1;
    }

    /*
    void advance(int &cr,int &cc,int n,int i)
    {
        bool rev=0;
        if(n%2==0)
            rev=(cr%2==0);
        else
            rev=(cr%2!=0);
        
        if(rev)
        {
            if(cc-i>=0)
                cc-=i;
            else if(cr>0)
            {
                cr--;
                i-=cc;
                i--;
                cc=0;
                advance(cr,cc,n,i);
            }                
            else
            {
                cc=n;
                cr=n;
            }
        }
        else
        {
            if(cc+i<n)
                cc+=i;
            else if(cr>0)
            {
                cr--;
                i-=(n-cc);
                cc=n-1;
                advance(cr,cc,n,i);
            }                
            else
            {
                cc=n;
                cr=n;
            }
        }
    }
    
    void find(int &cr,int &cc,vector<vector<int>>& a,int n)
    {
        
        int x=a[cr][cc]-1;
        cr=n-x/n-1;
        cc=x%n;
        
        bool rev=0;
        if(n%2==0)
            rev=(cr%2==0);
        else
            rev=(cr%2!=0);
        
        if(rev)
            cc=n-cc-1;
    }
    
    int snakesAndLadders(vector<vector<int>>& a) {
        int n=a.size();
        
        if(n==1)
            return 0;
        
        int i;
        int er=0,ec,sr=n-1,sc=0;
        
        if(n%2==0)
            ec=0;
        else
            ec=n-1;
        
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool> (n,0));
        
        if(a[sr][sc]>1)
            find(sr,sc,a,n);
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        vis[sr][sc]=1;
        
        while(!q.empty())
        {
            int s=q.size();
            ans++;
            
            while(s--)
            {
                sr=q.front().first;
                sc=q.front().second;
                q.pop();

                for(i=1;i<=6;i++)
                {
                    int cr=sr,cc=sc;
                    advance(cr,cc,n,i);
                    
                    if(cr==n && cc==n)
                        break;
                    
                    if(a[cr][cc]>0)
                        find(cr,cc,a,n);
                                        
                    if(cr==er && cc==ec)
                        return ans;
                    
                    if(!vis[cr][cc])
                    {
                        q.push({cr,cc});
                        vis[cr][cc]=1;
                    }
                }
            }
        }
        return -1;
    }
    */
};