class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;
        queue<int> q;
        
        for(int i=1;i<=9;i++)
            q.push(i);
        
        while(--n)
        {
            int s=q.size();
            while(s--)
            {
                int num=q.front();
                int digit=num%10;
                q.pop();
                
                if(digit+k<=9)
                    q.push(num*10+digit+k);
                
                if(k!=0 && digit-k>=0)
                    q.push(num*10+digit-k);
            }
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
    
    /*
    vector<int> ans;
    
    void helper(int digit,int n,int k,int num)
    {
        if(n==0)
        {
            if(num!=0)
                ans.push_back(num);
            
            return;
        }
        
        if(digit-k>=0)
            helper(digit-k,n-1,k,num*10+digit-k);
        
        if(digit+k<=9 && k!=0)
            helper(digit+k,n-1,k,num*10+digit+k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1;i<=9;i++)
        helper(i,n-1,k,i);
        
        return ans;
    }
    */
};