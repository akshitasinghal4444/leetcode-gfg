class Solution {
public:
    
    string convert(int n)
    {
        string s="";
        
        while(n>0)
        {
            s+=((n%2)+'0');
            n/=2;
        }
        
        while(s.length()<8)
            s+='0';
        
        reverse(s.begin(),s.end());
        return s;
    }
    
    int count1(string s)
    {
        int n=0;
        
        for(char c:s)
        {
            if(c=='1')
                n++;
            else
                break;
        }
        
        return n;
    }
    
    bool validUtf8(vector<int>& data) {
        int i,n=data.size();
        
        i=0;
        while(i<n)
        {
            string s=convert(data[i++]);
            // cout<<s<<" ";
            
            if(s[0]=='0')
                continue;
            
            int l=count1(s);
            // cout<<l<<" ";
            if(l>4 || l==1)
                return 0;
                
            l=l-1;
            while(l && i<n)
            {
                s=convert(data[i++]);
                l--;
                
                // cout<<s<<" ";
                if(s[0]!='1' || s[1]!='0')
                    return 0;
            }
            // cout<<l<<" "; 
            if(l>0)
                return 0;
            
            // cout<<endl;
        }
        // cout<<endl;
        return 1;
    }
};