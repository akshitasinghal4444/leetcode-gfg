class Solution {
public:
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
};