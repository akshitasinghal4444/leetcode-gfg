class Solution {
public:
    int findPairs(vector<int>& a, int k)
    {
        int n=a.size();
        unordered_map<int,int> m;
        int i,ans=0;
        
        for(i=0;i<n;i++)
            m[a[i]]++;
        
        if(k==0)
        {
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second>1)
                    ans++;
            }
            return ans;
        }
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            int x=it->first;
            if(m.find(x+k)!=m.end())
                ans++;
        }
        return ans;
        
    }
    
    /*
    int findPairs(vector<int>& a, int k) {
        int n=a.size();
        int i,ans=0;
        sort(a.begin(),a.end());
        
        if(k==0)
        {
            for(i=1;i<n;i++)
            {
                if(a[i]==a[i-1] && (i==1 || a[i]!=a[i-2]))
                    ans++;
            }
            return ans;
        }
        
        unordered_set<int> s;
        for(i=0;i<n;i++)
        {
            if(i!=0 && a[i]==a[i-1])
                continue;
            
            if(!s.empty())
            {
                if(s.find(a[i]-k)!=s.end())
                    ans++;
            }
            s.insert(a[i]);
        }
        return ans;
    }
    */
};