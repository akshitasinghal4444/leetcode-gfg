class Solution {
public:
    /*
    int maximum69Number (int num) {
        string s=to_string(num);
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        
        return stoi(s);
    }
    */
    
    int maximum69Number (int n)
    {
        int i;
        int ans=0;
        bool f=0;
        
        for(i=10000;i>0;i/=10)
        {
            if(!f && n/i==6)
            {
                ans=ans*10+9;
                f=1;
            }       
            else
                ans=ans*10+(n/i);
            
            n%=i;   
            
      }
                
        return ans;
    }
};