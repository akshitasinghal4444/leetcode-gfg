class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        vector<int> ans;
        deque<int> q;
        
        int i;
        for(i=0;i<k;i++)
        {
            while(!q.empty() && q.front()<a[i])
                q.pop_front();
            q.push_front(a[i]);
        }
        
        ans.push_back(q.back());
        
        for(;i<n;i++)
        {
            if(q.back()==a[i-k])
                q.pop_back();
            
            while(!q.empty() && q.front()<a[i])
                q.pop_front();
            q.push_front(a[i]);
            
            ans.push_back(q.back());
        }
        
        return ans;
    }
};