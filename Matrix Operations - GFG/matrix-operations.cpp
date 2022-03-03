// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> dfs(vector<vector<int>> &a,int m,int n,int i,int j,int dir)
    {
        int x,y;
        
        if(a[i][j]==1)
        {
            dir++;
            dir=dir%4;
            a[i][j]=0;
        }
        
        switch(dir)
        {
            case 0:x=i-1;
                  y=j;
                  break;
            case 1:x=i;
                  y=j+1;
                  break;
            case 2:x=i+1;
                  y=j;
                  break;
            case 3:x=i;
                  y=j-1;
                  break;
        }
        
        if(x>=0 && y>=0 && x<m && y<n)
        return dfs(a,m,n,x,y,dir);
        
        return {i,j};
    }
    
    pair<int,int> endPoints(vector<vector<int>> a){
        //code here
        int m,n;
        m=a.size();
        n=a[0].size();
        
        int i,j;
        
        return dfs(a,m,n,0,0,1);
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends