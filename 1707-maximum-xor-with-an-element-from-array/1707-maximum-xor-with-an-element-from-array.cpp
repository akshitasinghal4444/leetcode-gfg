// struct Node{
//     Node* left;
//     Node* right;
    
//     Node(){
//         left = NULL;
//         right = NULL;
//     }
// };

// class Trie{
//     Node* root;
// public:
//     Trie(){
//         root = new Node();
//     }
    
//     void insert(int data){
//         Node* temp = root;
//         for(int i = 31; i >= 0; i--){
//             int bit = (data >> i) & 1;
//             if(bit == 0){
//                 if(temp->left == NULL){
//                     temp->left = new Node();
//                 }
//                 temp = temp->left;
//             }
//             else{
//                 if(temp->right == NULL){
//                     temp->right = new Node();
//                 }
//                 temp = temp->right;
//             }
//         }
//     }
    
//     int max_xor_helper(int data){
//         Node* temp = root;
//         int max_xor_val = 0;
//         for(int i = 31; i >= 0; i--){
//             int bit = (data >> i) & 1;
//             if(bit == 0){
//                 if(temp->right != NULL){
//                     max_xor_val += (1 << i);
//                     temp = temp->right;
//                 }
//                 else temp = temp->left;
//             }
//             else{
//                 if(temp->left != NULL){
//                     max_xor_val += (1 << i);
//                     temp = temp->left;
//                 }
//                 else temp = temp->right;
//             }
//         }
//         return max_xor_val;
//     }
// };

// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<pair<pair<int, int>, int> > newQueries;
//         for(int i = 0; i < queries.size(); i++){
//             newQueries.push_back({{queries[i][0], queries[i][1]}, i});
//         }
        
//         sort(newQueries.begin(), newQueries.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
//             return a.first.second < b.first.second;
//         });
        
//         sort(nums.begin(), nums.end());
        
//         vector<int> res(queries.size(), -1);
//         int index = 0;
//         Trie* myTrie = new Trie();
        
//         for(int i = 0; i < newQueries.size(); i++){
//             int data = newQueries[i].first.first;
//             int limit = newQueries[i].first.second; 
//             int idx = newQueries[i].second;
            
//             while(index < nums.size() && nums[index] <= limit){
//                 myTrie->insert(nums[index++]);
//             }
            
//             if(index > 0){
//                 res[idx] = myTrie->max_xor_helper(data);
//             }
//         }
        
//         return res;
//     }
// };


class Solution {
public:
    struct trie
    {
        trie *next[2];
    }*root;
    
    void insert(int n)
    {
        trie *t=root;
        
        for(int i=31;i>=0;i--)
        {
            int x=(n>>i)&1;
            if(!t->next[x])
                t->next[x]=new trie();
            t=t->next[x];
        }
    }
    
    int getxor(int n)
    {
        trie *t=root;
        int ans=0;
        
        for(int i=31;i>=0;i--)
        {
            int x=(n>>i)&1;
                        
            if(t->next[!x])
            {
                ans+=(1<<i);
                t=t->next[!x];
            }
            else if(t->next[x])
                t=t->next[x];
            else
                return -1;
        }
        
        return ans;
    }
    
    // static bool comp(pair<pair<int,int>int> a,pair<pair<int,int>int> b)
    // {
    //     return a[1]<b[1];
    // }
    
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& qu) {
        
        root=new trie();
        int n1=a.size(),n2=qu.size();
        int i,j=0;        
        
        vector<int> ans(n2);
        vector<pair<pair<int,int>,int>> q;
        
        for(i=0;i<n2;i++)
        {
            q.push_back({{qu[i][1],qu[i][0]},i});
        }
        
        sort(a.begin(),a.end());
        sort(q.begin(),q.end());
           
        for(i=0;i<n2;i++)
        {
            int x,m,in;
            x=q[i].first.second;
            m=q[i].first.first;
            in=q[i].second;
            
            for(j;j<n1;j++)
            {
                if(a[j]>m)
                    break;
                insert(a[j]);
                    
            }
            ans[in]=getxor(x);
        }
        return ans;
    }
};
