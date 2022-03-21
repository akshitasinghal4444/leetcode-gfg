class Solution {
public:
    /*
    void advance(int &cr,int &cc,int sr,int sc,int n)
    {
        bool rev=0;
        rev=(cr%2==0);
        
        if(rev)
        {
            if(cc>0)
                cc--;
            else if(cr>0)
                cr--;
            else
            {
                cc=n;
                cr=n;
            }
        }
        else
        {
            if(cc<n-1)
                cc++;
            else if(cr>0)
                cr--;
            else
            {
                cc=n;
                cr=n;
            }
        }
    }
    
    int minsteps(vector<vector<int>>& a,int sr,int sc,int n,int er,int ec)
    {
        if(sr==er && sc==ec)
            return 0;
        
        if(a[sr][sc]!=-1)
            
        int i;
        int ans=INT_MAX;
        
        for(i=1;i<=6;i++)
        {
            int cr,cc;
            advance(cr,cc,sr,sc,n);
            
            if(cr!=n && cc!=n)
                ans=min(ans,1+minsteps(a,cr,cc,n,er,ec));
        }
        return ans;
    }
    
    int snakesAndLadders(vector<vector<int>>& a) {
        int n=a.size();
        int i,j;
        int er=0,ec;
        
        if(n%2==0)
            ec=0;
        else
            ec=n-1;
        
        int x=minsteps(a,n-1,0,n,er,ec);
        
        if(x==INT_MAX)
            return -1;
        
        return x;
    }
    */
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
                
                // cout<<sr<<" "<<sc<<":";

                for(i=1;i<=6;i++)
                {
                    int cr=sr,cc=sc;
                    advance(cr,cc,n,i);
                    
                    if(cr==n && cc==n)
                        break;
                    
                    if(a[cr][cc]>0)
                        find(cr,cc,a,n);
                    
                    // cout<<cr<<","<<cc<<"|";
                    
                    if(cr==er && cc==ec)
                        return ans;
                    
                    if(!vis[cr][cc])
                    {
                        q.push({cr,cc});
                        vis[cr][cc]=1;
                    }
                }
                // cout<<endl;
            }
            // cout<<endl;
        }
        return -1;
    }
};