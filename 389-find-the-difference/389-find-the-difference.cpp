class Solution {
public:
    char findTheDifference(string s, string t)
    {
        int n=s.length();
        int x=0,i;
        
        for(i=0;i<n;i++)
        {
            x^=t[i]^s[i];
        }
        x^=t[i];
        return x;
    }
    
    /*
    char findTheDifference(string s, string t)
    {
        int n=s.length();
        int sum=0,i;
        
        for(i=0;i<n;i++)
        {
            sum+=t[i]-s[i];
        }
        sum+=t[i];
        return sum;
    }
    */
    
    /*
    char findTheDifference(string s, string t) {
        int f[26]={0};
        
        int n=s.length(),i;
        for(i=0;i<n;i++)
        {
            f[s[i]-'a']++;
            f[t[i]-'a']--;
        }
        f[t[i]-'a']--;
        
        for(i=0;i<26;i++)
        {
            if(f[i]==-1)
                return (i+'a');
        }
        return 'a';
    }
    */
};