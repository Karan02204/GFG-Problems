/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* Pre(Node* root , int key){
        Node* answer = NULL;
        
        while(root){
            if(root->data < key){
                answer = root;
                root = root->right;
            } else if(root->data > key){
                root = root->left;
            } else{
                root = root->left;
            }
        }
        
        return answer;
    }
    
    Node* Suc(Node* root , int key){
        Node* answer = NULL;
        
        while(root){
            if(root->data < key){
                root = root->right;
            } else if(root->data > key){
                answer = root;
                root = root->left;
            } else{
                root = root->right;
            }
        }
        
        return answer;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> result;
        
        Node* pred = Pre(root , key);
        Node* succ = Suc(root , key);
        
        result.push_back(pred);
        result.push_back(succ);
        
        return result;
    }
};