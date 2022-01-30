// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isPossible(bool a[101][101],int in,int c,int v,vector<int> &color)
{
    int j;
    for(j=0;j<v;j++)
    {
        if(a[in][j] && color[j]==c)
        return 0;
    }
    return 1;
}

bool graphColoring(bool a[101][101], int m, int v,int in,vector<int> &color)
{
    if(in==v)
    return 1;
    
    int i;
    for(i=0;i<m;i++)
    {
        color[in]=i;
        if(isPossible(a,in,i,v,color))
        {
            if(graphColoring(a,m,v,in+1,color))
            return 1;
        }
    }
    color[in]=-1;
    return 0;
}

bool graphColoring(bool a[101][101], int m, int v)
{
    // your code here
    vector<int> color(v,-1);
    return graphColoring(a,m,v,0,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends