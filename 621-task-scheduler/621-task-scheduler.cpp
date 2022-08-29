class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int f[26]={0};
        priority_queue<int> pq;
        int ans=0,c=0;
        
        for(char c:tasks)
            f[c-'A']++;
        
        for(int x:f)
        {
            if(x!=0)
                pq.push(x);
        }
        
        while(c<tasks.size())
        {
            int n1=n+1;
            vector<int> t;
            
            while(n1 && !pq.empty())
            {
                c++;
                n1--;
                
                if(pq.top()>1)
                t.push_back(pq.top()-1);
                
                pq.pop();
            }
            
            if(t.size()>0)
            ans+=n+1;
            else
            ans+=n+1-n1;
            
            for(int i=0;i<t.size();i++)
                pq.push(t[i]);    
        }
        
        return ans;
    }
};

