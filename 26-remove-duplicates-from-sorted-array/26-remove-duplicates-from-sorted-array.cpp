class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i,j,n=a.size();
        for(i=0,j=0;i<n;i++)
        {
            if(i==0 || a[i]!=a[i-1])
                a[j++]=a[i];
        }
        
        return j;
    }
};