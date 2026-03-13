/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
public:
    int minNode;
    int maxNode;
    int maxSize;
    
    NodeValue(int minNode , int maxNode , int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue largestBstHelper(Node* root){
        if(!root){
            return NodeValue(INT_MAX , INT_MIN , 0);
        }
        
        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue(min(root->data , left.minNode) , max(root->data , right.maxNode) , 1 + left.maxSize + right.maxSize);
        }
        
        return NodeValue(INT_MIN , INT_MAX , max(left.maxSize , right.maxSize));
    }
    
    int largestBst(Node *root) {
        // Your code here
        return largestBstHelper(root).maxSize;
    }
};