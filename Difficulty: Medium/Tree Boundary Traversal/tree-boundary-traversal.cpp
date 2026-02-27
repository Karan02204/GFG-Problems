/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftView(Node* root , vector<int>& result){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL) return;
        
        result.push_back(root->data);
        
        if(root->left!=NULL){
            leftView(root->left , result);
        } else{
            leftView(root->right , result);
        }
    }
    
    void leafNode(Node* root , vector<int>& result){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            result.push_back(root->data);
            return;
        }
        
        leafNode(root->left , result);
        leafNode(root->right , result);
    }
    
    void rightView(Node* root , vector<int>& rightBoundary){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        rightBoundary.push_back(root->data);
        
        if(root->right!=NULL){
            rightView(root->right , rightBoundary);
        } else{
            rightView(root->left , rightBoundary);
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        
        if(root == NULL) return result;
        result.push_back(root->data);
        
        leftView(root->left , result);
        
        if(!(root->left == NULL && root->right == NULL)){
            leafNode(root,result);
        }
        
        vector<int> rightBoundary;
        rightView(root->right , rightBoundary);
        
        reverse(rightBoundary.begin() , rightBoundary.end());
        result.insert(result.end() , rightBoundary.begin(), rightBoundary.end());
        
        return result;
    }
};