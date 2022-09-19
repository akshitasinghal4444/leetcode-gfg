class Solution {
public:
    
    bool comp(int *f1,int *f2)
    {
        int i;
        for(i=0;i<26;i++)
        {
            if(f1[i]!=f2[i])
                return 0;
        }
        return 1;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1,n2;
        n1=s1.length();
        n2=s2.length();
        
        if(n2<n1)
            return 0;
        
        int i,j;
        int f1[26]={0},f2[26]={0};
        
        for(i=0;i<n1;i++)
        {
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        
        if(comp(f1,f2))
            return 1;
        
        for(i;i<n2;i++)
        {
            f2[s2[i]-'a']++;
            f2[s2[i-n1]-'a']--;
            if(comp(f1,f2))
                return 1;
        }
        return 0;
    }
    
    /*
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();
        int i,j;
        vector<int> f1(26,0),f2(26,0);
        
        if(n1>n2)
            return 0;
        
        for(i=0;i<n1;i++)
        {
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
            
        if(f1==f2)
            return 1;
        
        for(i;i<n2;i++)
        {
            f2[s2[i-n1]-'a']--;
            f2[s2[i]-'a']++;
            
            if(f1==f2)
                return 1;
        }
        
        return 0;
    }
    */
};