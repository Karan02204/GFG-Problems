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
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        map<int , int> mp; // index , node
        
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                Node* node = q.front().first;
                int index = q.front().second;
                
                q.pop();
                
                if(mp.find(index) == mp.end()){
                    mp[index] = node->data;
                }
                
                if(node->left) q.push({node->left,index-1});
                if(node->right) q.push({node->right , index+1});
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};