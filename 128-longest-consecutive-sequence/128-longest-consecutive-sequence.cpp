class Solution {
public:
    int longestConsecutive(vector<int>& a)
    {
        unordered_set<int> s(a.begin(),a.end());
        int ans=0;
        
        for(int n:s)
        {
            if(s.find(n-1)!=s.end())
                continue;
            
            int c=1;
            while(s.find(n+1)!=s.end())
            {
                c++;
                n++;
            }
            
            ans=max(ans,c);
        }
        
        return ans;
    }
    
};