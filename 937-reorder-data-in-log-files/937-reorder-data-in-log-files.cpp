class Solution {
public:
    bool isdigitlog(string s)
    {
        int i,n=s.length();
        for(i=0;i<n;i++)
        {
            if(s[i]==' ')
                break;
        }
        
        i++;
        return (s[i]>='0' && s[i]<='9');
    }
    
    static bool comp(string s1,string s2)
    {
        int i,j,n1=s1.length(),n2=s2.length();
        
        for(i=0;i<n1;i++)
        {
            if(s1[i]==' ')
                break;
        }        
        
        for(j=0;j<n2;j++)
        {
            if(s2[j]==' ')
                break;
        }        
        
        int x=(s1.substr(i+1)).compare(s2.substr(j+1));
        if(x==0)
        {
            return (s1.substr(0,i+1)).compare(s2.substr(0,j+1))<=0;
        }
        
        return x<0;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter,digit,ans;
        int n=logs.size();
        int i;
        
        for(i=0;i<n;i++)
        {
            if(isdigitlog(logs[i]))
                digit.push_back(logs[i]);
            else
                letter.push_back(logs[i]);
        }
        
        sort(letter.begin(),letter.end(),comp);
        
        for(string s:letter)
            ans.push_back(s);
        
        for(string s:digit)
            ans.push_back(s);
        
        return ans;
    }
};