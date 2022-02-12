class Solution {
public:
    int ladderLength(string b, string e, vector<string>& a) {
        
        unordered_set<string> s;
        for(string str:a)
            s.insert(str);
        
        if(s.find(e)==s.end())
            return 0;
        
        int ans=0;
        queue<string> q;
        q.push(b);
        
        while(!q.empty())
        {
            int qs=q.size();
            ans++;
            while(qs--)
            {
                string s1=q.front();
                string s2=s1;
                q.pop();
                
                int i;
                char j;
                int l=s1.length();
                
                for(i=0;i<l;i++)
                {
                    for(j='a';j<='z';j++)
                    {
                        if(s1[i]==j)
                            continue;
                        
                        s1[i]=j;
                        if(s.find(s1)!=s.end())
                        {
                            if(s1==e)
                                return ans+1;
                            q.push(s1);
                            s.erase(s1);
                        }
                    }
                    s1=s2;
                }
            }
        }
        return 0;
    }
};