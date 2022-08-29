class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1=v1.length(),n2=v2.length();
        int i=0,j=0;
        
        while(i<n1 || j<n2)
        {
            string s1="0",s2="0";
            int x1,x2;
            
            while(i<n1 && v1[i]!='.')
                s1+=v1[i++];
            i++;
            
            while(j<n2 && v2[j]!='.')
                s2+=v2[j++];
            j++;
            
            x1=stoi(s1),x2=stoi(s2);
            
            if(x1<x2)
                return -1;
            else if(x2<x1)
                return 1;
        }
        
        return 0;
    }
};