class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a1, vector<vector<int>>& a2) {
        int n1=a1.size(),n2=a2.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        
        while(i<n1 && j<n2)
        {
            int l=max(a1[i][0],a2[j][0]);
            int r=min(a1[i][1],a2[j][1]);
            
            if(l<=r)
                ans.push_back({l,r});
            
            if(a1[i][1]<=a2[j][1])
                i++;
            else
                j++;
        }
        
        return ans;
    }
    
    /*
    vector<int> find_common(vector<int> &a ,vector<int> &b)
    {
        if(a[0]>b[1] || b[0]>a[1])
            return {};
        
        return {max(a[0],b[0]),min(a[1],b[1])};
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a1, vector<vector<int>>& a2) {
        int n1=a1.size(),n2=a2.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        
        while(i<n1 && j<n2)
        {
            auto v=find_common(a1[i],a2[j]);
            
            if(v.size()>0)
                ans.push_back(v);
            
            if(a1[i][1]<=a2[j][1])
                i++;
            else
                j++;
        }
        
        return ans;
    }
    */
};