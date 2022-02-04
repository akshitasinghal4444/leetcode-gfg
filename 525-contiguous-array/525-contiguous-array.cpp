class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n=a.size();
        int i,sum=0,maxl=0;
        unordered_map<int,int> m;
        
        for(i=0;i<n;i++)
        {
            if(a[i])
                sum++;
            else
                sum--;
            
            if(sum==0)
                maxl=max(maxl,i+1);
            else if(m.find(sum)!=m.end())
                maxl=max(maxl,i-m[sum]);
            else
                m[sum]=i;
        }
        return maxl;
    }
};