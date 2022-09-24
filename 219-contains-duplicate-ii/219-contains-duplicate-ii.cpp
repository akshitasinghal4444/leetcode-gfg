class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_map<int,int> m;
        int i,n=a.size();
        
        for(i=0;i<n;i++)
        {
            if(m.find(a[i])!=m.end() && i-m[a[i]]<=k)
                return 1;
            
            m[a[i]]=i;   
        }
        
        return 0;
    }
};