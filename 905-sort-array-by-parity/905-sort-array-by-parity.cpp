class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int i,j,n=a.size();
        
        j=0;
        for(i=0;i<n;i++)
        {
            if(a[i]%2==0)
                swap(a[i],a[j++]);
        }
        
        return a;
    }
};