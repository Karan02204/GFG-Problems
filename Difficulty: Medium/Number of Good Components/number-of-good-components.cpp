
class Solution {
  public:
    void dfs(int node , vector<vector<int>>& adj , vector<bool>& visited , int& nodes , int& edgesum){
        visited[node] = true;
        nodes++;
        edgesum += adj[node].size();
        
        for(auto& neigh : adj[node]){
            if(!visited[neigh]){
                dfs(neigh , adj , visited , nodes , edgesum);
            }
        }
    }
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(v);
        int count = 0;
        
        for(auto& e : edges){
            int u = e[0] - 1;
            int w = e[1] - 1;
            
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        
        vector<bool> visited(v,false);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                int nodes = 0;
                int edgesum = 0;
                dfs(i , adj , visited , nodes , edgesum);
                
                int totalEdges = edgesum/2;
                
                if(totalEdges == (nodes*(nodes-1)/2)){
                    count++;
                }
            }
        }
        
        return count;
    }
};
