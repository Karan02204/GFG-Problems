/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        int left = 0 , right = 0;
        
        if(root->left) left += root->left->data;
        if(root->right) right+= root->right->data;
        
        
        
        if(root->data != left+right) return false;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
        
        
    }
};