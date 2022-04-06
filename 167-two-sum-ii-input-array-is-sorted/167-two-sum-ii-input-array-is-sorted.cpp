class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n=a.size();
        int i=0,j=n-1;
        
        while(i<j)
        {
            if(a[i]+a[j]==t)
                return {i+1,j+1};
            
            if(a[i]+a[j]<t)
                i++;
            else
                j--;
        }
        
        return {};
    }
};