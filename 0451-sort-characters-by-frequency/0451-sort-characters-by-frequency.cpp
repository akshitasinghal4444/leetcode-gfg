class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        string ans="";
        priority_queue<pair<int,char>> q;
        
        for(char c:s)
            m[c]++;
        
        for(auto it:m)
            q.push({it.second,it.first});
        
        while(!q.empty())
        {
            char c=q.top().second;
            int f=q.top().first;
            
            while(f--)
            ans+=c;
            
            q.pop();
        }
        
        return ans;
    }
};