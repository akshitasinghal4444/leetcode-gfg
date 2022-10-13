class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int i,j,n=a.size();
        int size[n],count[n];
        size[0]=1,count[0]=1;
        
        for(i=1;i<n;i++)
        {
            size[i]=0,count[i]=1;
            for(j=i-1;j>=0;j--)
            {
                if(a[j]<a[i])
                {
                    if(size[j]==size[i])
                    {
                        size[i]=size[j];
                        count[i]+=count[j];
                    }
                    else if(size[j]>size[i])
                    {
                        size[i]=size[j];
                        count[i]=count[j];
                    }
                }
            }
            
            size[i]++;
        }
        
        int mx=1,c=0;
        
        for(i=0;i<n;i++)
        {
            if(size[i]==mx)
                c+=count[i];
            else if(size[i]>mx)
            {
                mx=size[i];
                c=count[i];
            }
        }
        
        return c;
    }
};