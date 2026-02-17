class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        
        vector<int> result;
        result.push_back(-1);
        st.push(arr[arr.size()-1]);
        
        
        for(int i=arr.size()-2;i>=0;i--){
            while(!st.empty() && st.top() <= arr[i]) st.pop();
            if(st.empty()) result.push_back(-1);
            else result.push_back(st.top());
            st.push(arr[i]);
        }
        
        reverse(result.begin() , result.end());
        return result;
        
    }
};