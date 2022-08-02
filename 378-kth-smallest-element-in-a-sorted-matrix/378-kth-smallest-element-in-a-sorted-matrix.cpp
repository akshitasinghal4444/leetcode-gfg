class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int i,j,n=a.size();
        priority_queue<int> pq;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                pq.push(a[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
            
        return pq.top();
    }
};