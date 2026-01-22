class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> result;
        queue<int> q;
        
        q.push(0);
        vector<bool> visited (adj.size(),false);
        visited[0] = true;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            result.push_back(current);
            for(int i : adj[current]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return result;
    }
};