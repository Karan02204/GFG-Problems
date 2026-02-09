class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        queue<pair<int,int>> q;
        vector<int> answer;
        
        vector<int> dx = {0,1};
        vector<int> dy = {1,0};
        
        q.push({0,0});
        int startVal = matrix[0][0];
        matrix[0][0] = -1;   // mark visited immediately
        
        answer.push_back(startVal);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            int x = node.first;
            int y = node.second;
            
            for(int j = 0; j < 2; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(nx >= 0 && ny >= 0 && nx < r && ny < c && matrix[nx][ny] != -1){
                    q.push({nx, ny});
                    answer.push_back(matrix[nx][ny]); // store value
                    matrix[nx][ny] = -1;              // mark visited
                }
            }
        }
        
        return answer;
    }
};
