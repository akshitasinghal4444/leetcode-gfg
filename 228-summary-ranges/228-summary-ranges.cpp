class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n=a.size();
        
        if(n==0)
            return {};
        
        int i,st,end;
        vector<string> ans;
        
        st=a[0];
        end=a[0];
        
        for(i=1;i<n;i++)
        {
            if(a[i]==end+1)
                end++;
            else
            {
                string s=to_string(st);
                if(st!=end)
                {
                    s+="->";
                    s+=to_string(end);
                }
                    
                ans.push_back(s);
                st=end=a[i];
            }
        }
        string s=to_string(st);
        if(st!=end)
        {
            s+="->";
            s+=to_string(end);
        }
            
        ans.push_back(s);
        
        return ans;
        
    }
};