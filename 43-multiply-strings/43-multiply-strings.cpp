class Solution {
public:
    string multiply(string n1, string n2) 
    {
        if(n1=="0" || n2=="0")
            return "0";
        
        int l1=n1.length(),l2=n2.length();
        vector<int> res(l1+l2,0);
        string ans="";
        int i,j;
        
        for(i=l2-1;i>=0;i--)
        {
            for(j=l1-1;j>=0;j--)
            {
                res[i+j+1]+=((n2[i]-'0')*(n1[j]-'0'));
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]%=10;
            }
        }
        
        for(i=0;i<l1+l2;i++)
        {
            if(res[i]!=0)
                break;
        }
        
        for(i;i<l1+l2;i++)
            ans+=to_string(res[i]);
        
        return ans;
    }
    
    /*
    string add(string n1,string n2)
    {
        int i=n1.length()-1,j=n2.length()-1,c=0;
        string ans="";
        
        while(i>=0 || j>=0 || c)
        {
            if(i>=0)
               c+=n1[i--]-'0';
            
            if(j>=0)
                c+=n2[j--]-'0';
            
            ans+=to_string(c%10);
            c=c/10;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string multiply(string n1, string n2) {
        if(n1=="0" || n2=="0")
            return "0";
        
        int l1=n1.length(),l2=n2.length();
        int i,j,k=0,c=0,p=1;
        string ans="";
        
        for(i=l2-1;i>=0;i--)
        {
            string t="";
            for(j=l1-1;j>=0;j--)
            {
                p=(n2[i]-'0')*(n1[j]-'0');
                c+=p;
                
                t+=to_string(c%10);
                c=c/10;
            }
            
            while(c)
            {
                t+=to_string(c%10);
                c=c/10;
            }
            
            while(t.size()>1 && t.back()=='0')
                t.pop_back();
            
            reverse(t.begin(),t.end());
            
            for(j=0;j<k;j++)
                t.push_back('0');
            
            ans=add(ans,t);
            k++;
        }
        
        return ans;
    }
    */
};