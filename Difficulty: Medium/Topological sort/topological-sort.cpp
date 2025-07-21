class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
        }
        
        vector<int> Indegree(V,0);
        
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                Indegree[adj[i][j]]++;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<Indegree.size();i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int i=0;i<adj[node].size();i++){
                Indegree[adj[node][i]]--;
                if(Indegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        
        
        return ans;
    }
};