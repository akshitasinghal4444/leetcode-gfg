// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
    // Code here
    int i,j,l,r,ans,count[str.size()][26];
    vector<int> res;
    for(i=0;i<str.size();i++)
    {
        for(j=0;j<26;j++)
        count[i][j]=0;
    }
    for(i=0;i<str.size();i++)
    {
        count[i][str[i]-97]=1;
    }
     for(i=1;i<str.size();i++)
    {
        for(j=0;j<26;j++)
        count[i][j]+=count[i-1][j];
    }
    for(i=0;i<Query.size();i++)
    {
        ans=0;
        l=Query[i][0]-1;
        r=Query[i][1]-1;
        if(l==0)
        {
            for(j=0;j<26;j++)
            {
                if(count[r][j]>0)
                ans++;
            }
        }
        else
        {
            for(j=0;j<26;j++)
            {
                if(count[r][j]-count[l-1][j]>0)
                ans++;
            }
        }
        res.push_back(ans);
    }
    return res;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends