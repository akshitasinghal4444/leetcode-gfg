class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        int i,m=1e9+7;
        vector<pair<int,int>> a;
        priority_queue<int,vector<int>,greater<int>> q;
        long ans=0,sum=0;
        
        for(i=0;i<n;i++)
            a.push_back({e[i],s[i]});
        
        sort(a.begin(),a.end(),greater<pair<int,int>>());
        
        for(i=0;i<n;i++)
        {
            long eff=a[i].first;
            long sp=a[i].second;
            
            sum+=sp;
            
            q.push(sp);
            
            if(q.size()>k)
            {
                sum-=q.top();
                q.pop();
            }
            
            ans=max(ans,(eff*sum));
        }
        
        return ans%m;
    }
};