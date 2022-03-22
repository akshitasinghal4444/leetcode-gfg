class Solution {
public:
    string getSmallestString(int n, int k) {
        string s="";
        int i;
        
        for(i=0;i<n;i++)
        {
            s+='a';
            k--;
        }
        
        for(i=n-1;i>=0,k>0;i--)
        {
            if(k<25)
            {
                s[i]+=k;
                k=0;
            }
            else
            {
                s[i]+=25;
                k-=25;
            }
        }
        
        return s;
    }
};