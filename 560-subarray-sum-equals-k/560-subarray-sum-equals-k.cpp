class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();
        int i,ans=0,s=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(i=0;i<n;i++)
        {
            s+=a[i];
            ans+=m[s-k];
            m[s]++;
        }
        
        return ans;
    }
};