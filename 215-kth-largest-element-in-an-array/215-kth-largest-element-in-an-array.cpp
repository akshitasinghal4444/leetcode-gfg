class Solution {
public:
    /*
    int findKthLargest(vector<int>& a, int k) {
        sort(a.begin(),a.end(),greater<int>());
        return a[k-1];
    }
    */
    
    int findKthLargest(vector<int>& a, int k)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int x:a)
        {
            pq.push(x);
            if(pq.size()>k)
                pq.pop();
        }
        
//         while(pq.size()>1)
//             pq.pop();
        
        return pq.top();
    }
};