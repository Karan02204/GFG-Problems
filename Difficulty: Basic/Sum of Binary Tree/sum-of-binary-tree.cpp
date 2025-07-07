/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    void Helper(int& sum ,  Node* root){
        if(root == NULL){
            return;
        }
        
        Helper(sum,root->left);
        sum += root->data;
        Helper(sum,root->right);
    }
    int sumBT(Node* root) {
        // code here
        int sum = 0;
        Helper(sum,root);
        return sum;
        
    }
};