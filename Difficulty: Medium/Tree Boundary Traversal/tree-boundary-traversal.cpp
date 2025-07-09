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
    void leafNode(vector<int>& result , Node* root){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            result.push_back(root->data);
            return;
        }
        
        leafNode(result,root->left);
        leafNode(result,root->right);
        
    }
    
    void leftView(vector<int>& result,Node* root){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        result.push_back(root->data);
        if(root->left != NULL){
            leftView(result,root->left);
        } else{
            leftView(result,root->right);
        }
    }
    
    void rightView(vector<int>& result,Node* root){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        if(root->right != NULL){
            rightView(result,root->right);
        } else{
            rightView(result,root->left);
        }
        
        if(find(result.begin(),result.end(),root->data) == result.end()){
            result.push_back(root->data);
        }
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        if(root==NULL) return result;
        result.push_back(root->data);
        leftView(result,root->left);
        
        if(!(root->left == NULL && root->right == NULL)){
            leafNode(result,root);
        }
        
        vector<int> rightBoundary;
        rightView(rightBoundary,root->right);
        result.insert(result.end(),rightBoundary.begin(),rightBoundary.end());
        return result;
        
    }
};