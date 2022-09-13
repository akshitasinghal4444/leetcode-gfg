class Solution {
public:
    
    bool validUtf8(vector<int>& data)
    {
        int i,n=data.size();
        
        i=0;
        while(i<n)
        {
            int x=data[i++];
            int l;
            
            if(x>>7==0b0)
                continue;
            
            if(x>>3==0b11110)
                l=4;
            else if(x>>4==0b1110)
                l=3;
            else if(x>>5==0b110)
                l=2;
            else
                return 0;
            
            
            l=l-1;
            while(l && i<n)
            {
                if(data[i++]>>6!=0b10)
                    return 0;
                
                l--;
            }

            if(l>0)
                return 0;
            
        }
        
        return 1;
    }
    
    /*
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
            
            if(s[0]=='0')
                continue;
            
            int l=count1(s);
            if(l>4 || l==1)
                return 0;
                
            l=l-1;
            while(l && i<n)
            {
                s=convert(data[i++]);
                l--;
                
                if(s[0]!='1' || s[1]!='0')
                    return 0;
            }

            if(l>0)
                return 0;            
        }

        return 1;
    }
    */
};