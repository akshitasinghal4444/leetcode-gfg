class Solution {
public:
    int threeSumMulti(vector<int>& a, int t)
    {
        int n=a.size();
        int i,j,k;
        int m=1e9+7;
        long c=0;
        
        sort(a.begin(),a.end());
        
        for(i=0;i<n-2;i++)
        {
            if(a[i]>t)
                break;
            
            if(i>0 && a[i]==a[i-1])
                continue;
            
            j=i+1;
            k=n-1;
            
            while(j<k)
            {
                int s=a[i]+a[j]+a[k];
                
                if(s<t)
                    j++;
                else if(s>t)
                    k--;
                else
                {
                    // cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                    long c1=1,c2=1,c3=1;
                    
                    int i1=i;
                    while(i1<n-1 && a[i1]==a[i1+1])
                    {
                        i1++;
                        c1++;
                    }
                    
                    while(j<n-1 && a[j]==a[j+1])
                    {
                        j++;
                        c2++;
                    }
                    
                    while(k>j && a[k]==a[k-1])
                    {
                        k--;
                        c3++;
                    }
                    
                    if(a[i]==a[j] && a[j]==a[k])
                        c+=c1*(c1-1)*(c1-2)/6;
                    else if(a[i]==a[j])
                        c+=c1*(c1-1)/2*c3;
                    else if(a[j]==a[k])
                        c+=c1*c2*(c2-1)/2;
                    else
                        c+=c1*c2*c3;
                    
                    // cout<<c1<<" "<<c2<<" "<<c3<<" "<<c<<endl;
                    j++;
                    k--;
                }
            }
        }
        return c%m;
    }
    
    /*
    int threeSumMulti(vector<int>& a, int t) 
    {
        int n=a.size();
        unordered_map<int,long> mp;
        int i,j,m=1e9+7;
        long c=0;
        
        for(i=0;i<n;i++)
        {
            c+=mp[t-a[i]];
            
            for(j=0;j<i;j++)
                mp[a[i]+a[j]]++;
        }
        
        return c%m;
    }
    */
    
    /*
    int threeSumMulti(vector<int>& a, int t) {
        int n=a.size();
        unordered_map<int,long> mp;
        int i,m=1e9+7;
        long c=0;
        
        for(i=0;i<n;i++)
            mp[a[i]]++;
        
        for(auto it1:mp)
        {
            if(it1.first>t)
                continue;
            
            for(auto it2:mp)
            {
                
                int x=it1.first;
                int y=it2.first;
                int z=t-x-y;
                
                if(mp.find(z)!=mp.end())
                {
                    if(x==y && y==z)
                        c+=mp[x]*(mp[x]-1)*(mp[x]-2)/6;
                    else if(x==y && y!=z)
                        c+=mp[x]*(mp[x]-1)/2*mp[z];
                    else if(x<y && y<z)
                        c+=mp[x]*mp[y]*mp[z];
                    
                    c=c%m;
                }
            }
        }
        
        return c;
    }
    */
};