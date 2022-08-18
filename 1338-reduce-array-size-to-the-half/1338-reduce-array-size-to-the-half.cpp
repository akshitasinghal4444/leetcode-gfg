class Solution {
public:
    int minSetSize(vector<int>& a) {
        int i,n=a.size();
        int x=0,c=0,k=0;
        vector<int> f;
        
        sort(a.begin(),a.end());
        
        f.push_back(1);
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
                f[k]++;
            else
            {
                f.push_back(1);
                k++;
            }  
        }
            
        sort(f.begin(),f.end(),greater<int>());
        
        k=0;
        while(x<n/2)
        {
            x+=f[k++];
            c++;
        }
        
        return c;
    }
    
    /*
    int minSetSize(vector<int>& a) {
        int i,n=a.size();
        int x=0,c=0,k=0;
        unordered_map<int,int> f;
        vector<int> v;
        
        for(i=0;i<n;i++)
            f[a[i]]++;
        
        for(auto it:f)
            v.push_back(it.second);
        
        sort(v.begin(),v.end(),greater<int>());
        
        while(x<n/2)
        {
            x+=v[k++];
            c++;
        }
        
        return c;
    }
    */
    
    /*
    int minSetSize(vector<int>& a) {
        int i,n=a.size();
        int x=0,c=0;
        unordered_map<int,int> f;
        priority_queue<int> q;
        
        for(i=0;i<n;i++)
            f[a[i]]++;
        
        for(auto it:f)
            q.push(it.second);
        
        while(x<n/2)
        {
            x+=q.top();
            q.pop();
            c++;
        }
        
        return c;
    }
    */
};