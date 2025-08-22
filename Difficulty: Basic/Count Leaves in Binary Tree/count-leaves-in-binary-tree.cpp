/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    void Helper(Node* root , int& count){
        if(!root) return;
        
        if(!root->left && !root->right) count++;
        Helper(root->left,count);
        Helper(root->right,count);
    }
    int countLeaves(Node* root) {
        // write code here
        int count = 0;
        Helper(root,count);
        
        return count;
    }
};