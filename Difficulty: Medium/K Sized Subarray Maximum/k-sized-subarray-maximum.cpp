class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> dq;
        vector<int> result;
        
        int i=0,j=0;
        while(j<arr.size()){
            while(!dq.empty() && arr[dq.back()] <= arr[j]){
                dq.pop_back();
            }
            
            dq.push_back(j);
            
            while(!dq.empty() && dq.front() < i){
                dq.pop_front();
            }
            
            
            if(j-i+1 == k){
                result.push_back(arr[dq.front()]);
                i++;
            }
            j++;
        }
        
        
        return result;
    }
};