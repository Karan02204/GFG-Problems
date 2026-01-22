class Solution {
  public:
    void DFS(int node , vector<vector<int>>& adj , vector<bool>& visited , vector<int>& result){
        visited[node] = true;
        result.push_back(node);
        
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                DFS(neigh , adj , visited , result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited (n , false);
        vector<int> result;
        
        DFS(0,adj,visited,result);
        return result;
    }
};