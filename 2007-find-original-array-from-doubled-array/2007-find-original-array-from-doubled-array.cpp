class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int i,j,n=a.size();
        vector<int> ans;
        
        if(n%2!=0)
            return {};
        
        sort(a.begin(),a.end());
        unordered_map<int,int> m;
        
        for(i=0;i<n;i++)
            m[a[i]]++;
        
        for(i=0;i<n;i++)
        {
            if(m[a[i]]<=0)
                continue;
            
            m[a[i]]--;
            if(m[2*a[i]]<=0)
                return {};
            
            m[2*a[i]]--;
            ans.push_back(a[i]);
        }
        
        return ans;
    }
};