class Solution {
public:
    vector<int> getRow(int r) {
        if(r==0)
            return {1};
        if(r==1)
            return {1,1};
        
        vector<int> v,ans;
        v={1,1};
        int i,j;
        
        for(i=2;i<=r;i++)
        {
            ans={};
            for(j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    ans.push_back(1);
                else
                    ans.push_back(v[j]+v[j-1]);
            }
            v=ans;
        }
        return ans;
    }
};