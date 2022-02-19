class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        priority_queue<int>q;
        int ans=INT_MAX,mn=INT_MAX;
        
        for(int x:a)
        {
            if(x%2!=0)
                x*=2;
            
            q.push(x);
            
            mn=min(mn,x);
        }
        
        while(q.top()%2==0)
        {
            int x=q.top();
            q.pop();
            
            ans=min(ans,x-mn);
            
            x=x/2;
            mn=min(mn,x);
            q.push(x);
        }
        
        ans=min(ans,q.top()-mn);
        
        return ans;
    }
};


