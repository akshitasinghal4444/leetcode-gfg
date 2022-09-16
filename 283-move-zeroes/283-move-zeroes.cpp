class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i,j,n=a.size();
        
        for(i=0,j=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                swap(a[i],a[j]);
                j++;
            }
        }
    }
};