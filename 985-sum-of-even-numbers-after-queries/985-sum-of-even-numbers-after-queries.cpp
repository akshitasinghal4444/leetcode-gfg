class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& q) {
        
        vector<int> ans;
        int sum=0;
        
        for(int x:a)
        {
            if(x%2==0)
                sum+=x;
        }
                
        for(auto v:q)
        {
            if(a[v[1]]%2==0)
                sum-=a[v[1]];
            
            a[v[1]]+=v[0];
            
            if(a[v[1]]%2==0)
                sum+=a[v[1]];
            
            ans.push_back(sum);
        }
                    
        return ans;
    }
};