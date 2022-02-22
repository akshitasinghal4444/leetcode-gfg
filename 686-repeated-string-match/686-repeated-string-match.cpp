class Solution {
public:
    bool match(string a,string b)
    {
        int na=a.length(),nb=b.length();
        int i,j;
        
        for(i=0;i<=na-nb;i++)
        {
            for(j=0;j<nb;j++)
            {
                if(a[i+j]!=b[j])
                    break;
            }
            
            if(j==nb)
                return 1;
        }
        return 0;
    }
    
    int repeatedStringMatch(string a, string b) {
        
        int n=b.length();
        int x=1;
        string t=a;
        
        while(a.length()<n)
        {
            a+=t;
            x++;
        }
        
        if(match(a,b))
            return x;
        if(match(a+t,b))
          return x+1;
        return -1;
    }
};