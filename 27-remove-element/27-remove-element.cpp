class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int n=a.size();
        int i=0,j=n-1;
        
        while(i<n && a[i]!=val)
            i++;
        while(j>=0 && a[j]==val)
            j--;
        
        while(i<j)
        {
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            
            while(i<j && a[i]!=val)
                i++;
            while(j>i && a[j]==val)
                j--;
        }
        return i;
    }
};