/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node* root , vector<int> temp , vector<vector<int>>& result){
        if(!root) return;
        
        temp.push_back(root->data);
        if(!root->left && !root->right) result.push_back(temp);
        
        
        helper(root->left , temp , result);
        helper(root->right , temp , result);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> result;
        vector<int> temp;
        
        helper(root , temp , result);
        
        return result;
        
    }
};