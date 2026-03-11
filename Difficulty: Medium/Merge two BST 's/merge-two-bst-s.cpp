/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root , vector<int>& arr){
        if(!root) return;
        
        inorder(root->left , arr);
        arr.push_back(root->data);
        inorder(root->right , arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> arr1;
        vector<int> arr2;
        
        inorder(root1 , arr1);
        inorder(root2 , arr2);
        
        int n = arr1.size();
        int m = arr2.size();
        
        vector<int> merged;
        
        int i=0,j=0;
        
        while(i<arr1.size() && j < arr2.size()){
            if(arr1[i] <= arr2[j]) merged.push_back(arr1[i++]);
            else merged.push_back(arr2[j++]);
        }
        
        while(i<arr1.size()) merged.push_back(arr1[i++]);
        while(j<arr2.size()) merged.push_back(arr2[j++]);
        
        
        return merged;
    }
};