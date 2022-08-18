class Solution {
public:
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