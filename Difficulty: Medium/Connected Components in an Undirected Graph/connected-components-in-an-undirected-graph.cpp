class Solution {
  public:
    void dfs(int node , vector<vector<int>>& adj , vector<bool>& visited , vector<int>& temp){
        visited[node] = true;
        temp.push_back(node);
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour , adj , visited , temp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V,false);
        vector<vector<int>> result;
        
        for(int i=0;i<V;i++){
            vector<int> temp;
            if(!visited[i]){
                dfs(i,adj,visited,temp);
                result.push_back(temp);
            }
        }
        
        return result;
    }
};
