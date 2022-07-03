// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
void helper(map<string,int> m,string s,int index,string temp){
    if(index >= s.size()){
        temp.pop_back();
        ans.push_back(temp);
    }
    for(int i = index;i<s.size();i++){
        string str = s.substr(index,i-index+1);
        if(m.find(str) != m.end()){
            helper(m,s,i+1,temp+str+" ");
        }
    }
}
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        map<string,int> m;
        for(auto i : dict){
            m.insert({i,1});
        }
        helper(m,s,0,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends