class Solution {
public:
    int minSetSize(vector<int>& a) {
        int i,n=a.size();
        unordered_map<int,int> f;
        
        for(i=0;i<n;i++)
            f[a[i]]++;
        
        priority_queue<int> q;
        
        for(auto it:f)
            q.push(it.second);
        
        int x=0,c=0;
        while(x<n/2)
        {
            x+=q.top();
            q.pop();
            c++;
        }
        
        return c;
    }
};