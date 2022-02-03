class Solution {
public:
    int fourSumCount(vector<int>& a1, vector<int>& a2, vector<int>& a3, vector<int>& a4) {
        int n=a1.size();
        int i,j;
        int ans=0;
        
        unordered_map<int,int> m;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                m[a1[i]+a2[j]]++;
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                int s=a3[i]+a4[j];
                if(m.find(-s)!=m.end())
                {
                    ans+=m[-s];
                }
            }
        }
        
        return ans;
    }
};