/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(stack<int> &ans,TreeNode* r)
    {
        if(!r)
            return;
        
        inorder(ans,r->right);
        ans.push(r->val);
        inorder(ans,r->left);        
    }
    
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        vector<int> ans;
        stack<int> t1,t2;
        inorder(t1,r1);
        inorder(t2,r2);
        
        while(!t1.empty() && !t2.empty())
        {
            if(t1.top()<=t2.top())
            {
                ans.push_back(t1.top());
                t1.pop();
            }
            else
            {
                ans.push_back(t2.top());
                t2.pop();
            }
        }
        while(!t1.empty())
        {
            ans.push_back(t1.top());
            t1.pop();
        }
        
        while(!t2.empty())
        {
            ans.push_back(t2.top());
            t2.pop();
        }
        
        return ans;
    }
    
    /*
    void inorder(vector<int> &ans,TreeNode* r)
    {
        if(!r)
            return;
        inorder(ans,r->left);
        ans.push_back(r->val);
        inorder(ans,r->right);
    }
    
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        vector<int> t1,t2,ans;
        inorder(t1,r1);
        inorder(t2,r2);
        
        int n1,n2;
        n1=t1.size();
        n2=t2.size();
        
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(t1[i]<=t2[j])
            {
                ans.push_back(t1[i]);
                i++;
            }
            else
            {
                ans.push_back(t2[j]);
                j++;
            }
        }
        while(i<n1)
            ans.push_back(t1[i++]);
        
        while(j<n2)
            ans.push_back(t2[j++]);
        
        return ans;
    }
    */
};