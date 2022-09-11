class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a)
    {
        int i,n=a.size();
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
            if(ans.empty() || a[i]>0)
                ans.push_back(a[i]);
            else
            {
                while(!ans.empty() && ans.back()>0 && ans.back()<abs(a[i]))
                    ans.pop_back();
                
                if(ans.empty() || ans.back()<0)
                    ans.push_back(a[i]);
                
                if(!ans.empty() && ans.back()>0 && ans.back()==abs(a[i]))
                    ans.pop_back();
            }
        }
        
        return ans;
    }
    
    /*
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans=a;
        
        do
        {
            a=ans;
            ans={};
            int i,n=a.size();
            
            for(i=0;i<n-1;i++)
            {
                if((a[i]<0 && a[i+1]<0) || (a[i]>0 && a[i+1]>0) || (a[i]<0 && a[i+1]>0))
                    ans.push_back(a[i]);
                else
                {
                    if(abs(a[i])>abs(a[i+1]))
                        ans.push_back(a[i]);
                    else if(abs(a[i])<abs(a[i+1]))
                        ans.push_back(a[i+1]);
                    
                    i++;
                }
            }
            
            if(i==n-1)
                ans.push_back(a[i]);

        }while(a!=ans);
        
        return a;
    }
    */
};