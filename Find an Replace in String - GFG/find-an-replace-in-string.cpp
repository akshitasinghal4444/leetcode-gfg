// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
       // code here
     
       int prev=0;
      
       for(int i=0;i<Q;i++){
     
       string x=S.substr(prev+index[i],sources[i].size());
       
       if(x==sources[i]){
           S.erase(index[i]+prev,x.size());
           S.insert(index[i]+prev,targets[i]);
           prev+=targets[i].size()-sources[i].size();
       }
       
       }
       
       return S;
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends