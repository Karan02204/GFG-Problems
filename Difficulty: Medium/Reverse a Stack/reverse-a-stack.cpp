class Solution {
  public:
    void helper(stack<int>& st , int value){
        if(st.empty()){
            st.push(value);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        helper(st , value);
        
        st.push(top);
    }
    void reverseStack(stack<int> &st) {
        // code here
       if(st.empty()){
           return;
       }
       
       int top = st.top();
       st.pop();
       
       reverseStack(st);
       
       helper(st,top);
        
    }
};