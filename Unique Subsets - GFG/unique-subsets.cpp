// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    vector<vector<int>> ans;
    vector<int> t;
    
    void subsets(vector<int> &a, int in,int n)
    {
        if(in==n)
        {
            ans.push_back(t);
            return;
        }
        
        if(t.empty() || t.back()!=a[in])
        subsets(a,in+1,n);
        
        t.push_back(a[in]);
        subsets(a,in+1,n);
        t.pop_back();
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> a, int n)
    {
        // code here 
        sort(a.begin(),a.end());
        subsets(a,0,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends