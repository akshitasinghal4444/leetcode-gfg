class Solution {
public:
    int minRefuelStops(int t, int fuel, vector<vector<int>>& a) {
        priority_queue<int> pq;
        int pos=fuel;
        int i=0,n=a.size();
        int ans=0;
        
        while(pos<t && (i<n || !pq.empty()))
        {
            ans++;
            while(i<n && a[i][0]<=pos)
            {
                pq.push(a[i][1]);
                i++;
            }
            
            if(pq.empty())
                break;
            
            pos+=pq.top();
            pq.pop();
        }
        
        if(pos>=t)
            return ans;
        
        return -1;
    }
};