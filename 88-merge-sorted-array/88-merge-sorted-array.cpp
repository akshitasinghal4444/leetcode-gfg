class Solution {
public:
    
    void merge(vector<int>& a1, int n1, vector<int>& a2, int n2)
    {
        int i,j,k;
        i=n1-1,j=n2-1,k=n1+n2-1;
        
        while(i>=0 && j>=0)
        {
            if(a1[i]>a2[j])
                a1[k--]=a1[i--];
            else
                a1[k--]=a2[j--];
            
        }
        
        while(j>=0)
            a1[k--]=a2[j--];
    }
};