class Solution {
  public:
    bool detect(int src , vector<vector<int>>& adj , vector<int>& visited){
        visited[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1}); //src , parent
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto neigh : adj[node]){
                if(!visited[neigh]){
                    q.push({neigh,node});
                    visited[neigh] = 1;
                } else if(parent!=neigh){
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(i,adj,visited)) return true;
            }
        }
        
        return false;
    }
};