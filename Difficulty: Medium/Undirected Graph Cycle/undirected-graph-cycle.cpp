class Solution {
  public:
    bool dfs(int src , int parent , vector<vector<int>>& adj , vector<int>& visited){
        visited[src] = 1;
        
        for(auto neigh : adj[src]){
            if(!visited[neigh]){
                if(dfs(neigh,src,adj,visited)) return true;
            }
            else if(neigh!=parent){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited)) return true;
            }
        }
        
        return false;
    }
};