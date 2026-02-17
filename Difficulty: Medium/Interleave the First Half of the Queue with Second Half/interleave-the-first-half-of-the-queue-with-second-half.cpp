class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        stack<int> s1 , s2;
        
        int size = q.size();
        
        for(int i=0;i<size/2;i++){
            s1.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            s2.push(q.front());
            q.pop();
        }
        
        stack<int> s3;
        while(!s1.empty() && !s2.empty()){
            s3.push(s2.top());
            s2.pop();
            s3.push(s1.top());
            s1.pop();
        }
        
        while(!s3.empty()){
            q.push(s3.top());
            s3.pop();
        }
    }
};