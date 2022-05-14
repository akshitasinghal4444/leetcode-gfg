// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&a){
    // Code here
    int m=a.size(),n=a[0].size();
    int i,j;
    bool f=0;
    
    for(j=0;j<n;j++)
    {
        if(a[0][j]!=-1)
        {
            f=1;
            break;
        }
    }
    
    if(f==0)
    return 0;
    
    for(i=1;i<m;i++)
    {
        f=0;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==-1)
            {
                // cout<<a[i][j]<<" ";
                continue;
            }
            
            
            f=1;
            int x=-1;
            
            if(a[i-1][j]!=-1)
            x=max(x,a[i-1][j]);
            
            if(j-1>=0 && a[i-1][j-1]!=-1)
            x=max(x,a[i-1][j-1]);
            
            if(j+1<n && a[i-1][j+1]!=-1)
            x=max(x,a[i-1][j+1]);
            
            if(x==-1)
            a[i][j]=-1;
            else
            a[i][j]+=x;
            
            // cout<<a[i][j]<<" ";
        }
        
        // cout<<endl;
        if(f==0)
            break;
    }
    
    int ans=0;
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            ans=max(ans,a[i][j]);
        
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends