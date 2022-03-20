class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();
        int i,j,ans=INT_MAX;
        
        // c1 - store count of t[0] in top & bottom
        // c2 - store count of b[0] in top & bottom
        int c1[2]={0},c2[2]={0};
        bool f1=0,f2=0;
            
        for(i=0;i<n;i++)
        {
            if(t[i]==t[0])
                c1[0]++;
                
            if(b[i]==t[0])
                c1[1]++;
            
            if(t[i]==b[0])
                c2[0]++;
                
            if(b[i]==b[0])
                c2[1]++;
            
            if(t[i]!=t[0] && b[i]!=t[0])
                f1=1;
            
            if(t[i]!=b[0] && b[i]!=b[0])
                f2=1;
        }
            
        if(f1==0)
            ans=min(ans,n-max(c1[0],c1[1]));
        
        if(f2==0)
            ans=min(ans,n-max(c2[0],c2[1]));
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
    
    /*
    int check(vector<int>& t, vector<int>& b,int j,int n)
    {
        int tc=0,bc=0;
            
        for(int i=0;i<n;i++)
        {
            if(t[i]!=j && b[i]!=j)
                return INT_MAX;
            
            if(t[i]==j)
                tc++;
                
            if(b[i]==j)
                bc++;
        
        }
            
        return n-max(tc,bc);
    }
    
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();
        int i,j,ans=INT_MAX;
        
        ans=min(ans,check(t,b,t[0],n));
        ans=min(ans,check(t,b,b[0],n));
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
    */
    
    /*
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();
        int i,j,ans=INT_MAX;
        
        for(j=1;j<7;j++)
        {
            bool f=0;
            int tc=0,bc=0;
            
            for(i=0;i<n;i++)
            {
                if(t[i]==j)
                    tc++;
                
                if(b[i]==j)
                    bc++;
                
                if(t[i]!=j && b[i]!=j)
                {
                    f=1;
                    break;
                }
            }
            
            if(f==1)
                continue;
            
            ans=min(ans,n-max(tc,bc));
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
    */
    
    /*
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();
        int i,j,ans=INT_MAX;
        
        vector<vector<bool>> a(n,vector<bool>(7,0));
        
        for(i=0;i<n;i++)
        {
            a[i][t[i]]=1;
            a[i][b[i]]=1;
        }
        
        for(j=1;j<7;j++)
        {
            bool f=0;
            int tc=0,bc=0;
            
            for(i=0;i<n;i++)
            {
                if(t[i]==j)
                    tc++;
                
                if(b[i]==j)
                    bc++;
                
                if(a[i][j]==0)
                {
                    f=1;
                    break;
                }
            }
            
            if(f==1)
                continue;
            
            ans=min(ans,n-max(tc,bc));
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
    */
};