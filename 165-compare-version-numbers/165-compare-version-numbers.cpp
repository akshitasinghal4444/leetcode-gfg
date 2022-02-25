class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        int n1=v1.length(),n2=v2.length();
        int i=0,j=0;
        string t1="0",t2="0";
        
        while(i<n1 || j<n2)
        {
            while(i<n1 && v1[i]!='.')
            {
                t1+=v1[i];
                i++;
            }
            
            while(j<n2 && v2[j]!='.')
            {
                t2+=v2[j];
                j++;
            }
            
            // if(t1=="")
            //     t1="0";
            // if(t2=="")
            //     t2="0";
            
            if(stoi(t1)<stoi(t2))
                return -1;
            else if(stoi(t1)>stoi(t2))
                return 1;
            
            t1="0";
            t2="0";
            i++; 
            j++;
        }
        return 0;
    }
};