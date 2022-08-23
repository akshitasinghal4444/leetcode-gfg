class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans;
        
        for(int x:a)
            m[x]++;
        
        for(auto it:m)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        while(pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
            
        return ans;
    }
};