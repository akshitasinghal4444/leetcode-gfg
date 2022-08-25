class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int l=0,r=a[0].size()-1,t=0,b=a.size()-1;
        int i,dir=1;
        
        while(l<=r && t<=b)
        {
            
            if(dir==1)
            {   for(i=l;i<=r;i++)
                    ans.push_back(a[t][i]);
                t++;
                dir++;
            }
            else if(dir==2)
            {    
                for(i=t;i<=b;i++)
                    ans.push_back(a[i][r]);
                r--;
                dir++;
            }
            else if(dir==3)
            { 
                for(i=r;i>=l;i--)
                    ans.push_back(a[b][i]);
                b--;
                dir++;
            }
            else if(dir==4)
            { 
                for(i=b;i>=t;i--)
                    ans.push_back(a[i][l]);
                l++;
                dir=1;
            }
        }
        
        return ans;
    }
    
    /*
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int l=0,r=a[0].size()-1,t=0,b=a.size()-1,i;
        
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
    */
};