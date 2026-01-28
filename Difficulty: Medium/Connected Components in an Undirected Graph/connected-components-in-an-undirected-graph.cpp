class Solution {
  public:
    void DFS(int node , vector<vector<int>>& adj , vector<bool>& visited , vector<int>& temp){
        visited[node] = true;
        temp.push_back(node);
        
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                DFS(neigh , adj , visited, temp);
            }
        }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V);
        vector<vector<int>> result;
        
        for(int i=0;i<V;i++){
            vector<int> temp;
            if(!visited[i]){
                DFS(i,adj,visited,temp);
                result.push_back(temp);
            }
        }
        
        return result;
    }
};
