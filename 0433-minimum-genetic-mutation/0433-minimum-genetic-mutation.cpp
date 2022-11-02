class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s(bank.begin(),bank.end());
        
        if(s.find(end)==s.end())
            return -1;
        
        queue<string> q;
        char a[]={'A','C','G','T'};
        int c=0;
        
        q.push(start);
        
        if(s.find(start)!=s.end())
            s.erase(start);
        
        while(!q.empty())
        {
            int size=q.size();
            c++;
            
            while(size--)
            {
                start=q.front();
                q.pop();
                
                int i,j,l=start.length();
                
                for(i=0;i<l;i++)
                {
                    char ch=start[i];
                    
                    for(j=0;j<4;j++)
                    {
                        if(a[j]==ch)
                            continue;
                        
                        start[i]=a[j];
                        if(s.find(start)!=s.end())
                        {
                            if(start==end)
                                return c;
                            
                            q.push(start);
                            s.erase(start);
                        }
                    }
                    
                    start[i]=ch;
                }
            }
        }
        
        return -1;
    }
};