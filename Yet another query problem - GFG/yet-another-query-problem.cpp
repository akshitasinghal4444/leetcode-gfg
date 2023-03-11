//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int qu, vector<int> &a, vector<vector<int>> &q) {
        // code here
        unordered_map<int,int> f;
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--)
        {
            f[a[i]]++;
            a[i]=f[a[i]];
        }
        
        for(auto v:q)
        {
            int i,s=0;
            
            for(i=v[0];i<=v[1];i++)
            {
                if(a[i]==v[2])
                s++;
            }
            
            ans.push_back(s);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends