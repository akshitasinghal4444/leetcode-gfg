class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k)
    {
        int n=a.size();
        int l=a[0][0],h=a[n-1][n-1],ans;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            int rank=0;
            for(int i=0;i<n;i++)
                rank+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
            
            if(rank<k)
                l=mid+1;
            else
            {
                ans=mid;
                h=mid-1;
            }
        }
        
        return ans;
    }
    
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         // Store value of matrix size
//         int n = matrix.size();
        
//         int low = matrix[0][0]; // first element
//         int high = matrix[n-1][n-1]; // Last element
        
//         int mid, temp, count;
        
//         while(low < high){
//             mid = low + (high-low)/2;
//             temp = n - 1;
//             count = 0;
            
//             // For each row count the elements that are smaller than mid
//             for(int i = 0; i < n; i++){
                
//                 while(temp >= 0 && matrix[i][temp] > mid){
//                     temp--;
//                 }
//                 count+= (temp+1);
//             }
            
//             if(count < k){
//                 low = mid + 1;
//             }else{
//                 high = mid;
//             }
//         }
//         return low;
//     }
    
    /*
    int kthSmallest(vector<vector<int>>& a, int k) {
        int i,j,n=a.size();
        priority_queue<int> pq;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                pq.push(a[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
            
        return pq.top();
    }
    */
};