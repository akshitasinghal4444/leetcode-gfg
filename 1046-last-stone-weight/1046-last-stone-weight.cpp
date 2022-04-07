class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> q(s.begin(),s.end());
        
        while(q.size()>1)
        {
            int x=q.top();
            q.pop();
            
            int y=q.top();
            q.pop();
            
            y=abs(x-y);
            if(y!=0)
                q.push(y);
        }
        
        if(q.empty())
            return 0;
        return q.top();
    }
};