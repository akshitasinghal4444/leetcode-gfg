class Solution {
public:
    
    struct comp{
        bool operator()(pair<int,string> &a,pair<int,string> &b)
        {
            if(a.first==b.first)
                return a.second<b.second;
            
            return a.first>b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        vector<string> ans;
        
        for(string s:words)
            m[s]++;
        
        for(auto it:m)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
                pq.pop();
        }
            
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};