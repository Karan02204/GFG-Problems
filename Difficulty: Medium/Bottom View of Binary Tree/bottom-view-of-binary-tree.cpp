/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        
        map<int , int> mp;
        queue<pair<Node* , int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                Node* node = q.front().first;
                int index = q.front().second;
                
                q.pop();
                
                mp[index] = node->data;
                
                if(node->left) q.push({node->left , index-1});
                if(node->right) q.push({node->right , index+1});
            }
        }
        
        for(auto& it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};