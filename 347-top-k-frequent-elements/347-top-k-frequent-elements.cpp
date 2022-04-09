class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int n:a)
            m[n]++;
        
        for(auto it:m)
        {
            q.push({it.second,it.first});
            
            if(q.size()>k)
                q.pop();
        }
        
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};