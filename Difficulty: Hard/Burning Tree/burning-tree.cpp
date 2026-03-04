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
    void markParent(Node* root , unordered_map<Node* , Node*>& parent_track){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                
                if(node->left){
                    parent_track[node->left] = node;
                    q.push(node->left);
                }
                
                if(node->right){
                    parent_track[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    
    Node* findNode(Node* root , int target){
        if(!root) return NULL;
        if(root->data == target) return root;
        
        Node* left = findNode(root->left , target);
        if(left) return left;
        return findNode(root->right , target);
    }
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node* , Node*> parent_track;
        markParent(root, parent_track);
        
        unordered_map<Node* , bool> visited;
        Node* targetNode = findNode(root, target);
        visited[targetNode] = true;
        
        queue<Node*> q;
        q.push(targetNode);
        
        int time = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
            
            if(!q.empty()){
                time++;
            }
        }
        
        return time;
    }
};