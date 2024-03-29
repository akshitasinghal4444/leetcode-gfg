class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int i,n=a.size();
        vector<int> ans;
        deque<int> q;
        
        for(i=0;i<k;i++)
        {
            while(!q.empty() && q.front()<a[i])
                q.pop_front();
            
            q.push_front(a[i]);
        }
        ans.push_back(q.back());
        
        for(i;i<n;i++)
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