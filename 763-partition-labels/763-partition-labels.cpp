class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int i,n=s.length();
        
        unordered_map<char,int> last;
        
        for(i=0;i<n;i++)
            last[s[i]]=i;
        
        int b=0,e=0;
        
        for(i=0;i<n;i++)
        {
            if(i>e)
            {
                ans.push_back(e-b+1);
                b=i;
                e=last[s[i]];
            }
            else if(last[s[i]]>e)
                e=last[s[i]];
            
        }
        
        ans.push_back(e-b+1);
        
        return ans;
    }
};