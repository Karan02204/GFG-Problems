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
    void Helper(Node* root , vector<int>& result , int level){
        if(!root) return;
        if(result.size() == level) result.push_back(root->data);
        
        Helper(root->left , result , level+1);
        Helper(root->right , result , level+1);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
        if(!root) return result;
        
        Helper(root , result , 0);
        return result;
    }
};