class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        int minimum = INT_MAX;
        
        
        int i=0,j=0;
        
        int window = 0;
        
        for(auto i : arr){
            if(i == 1) window++;
        }
        
        int count = 0;
        while(j<arr.size()){
            if(arr[j] == 0){
                count++;
            }
            
            if(j-i+1 == window){
                minimum = min(minimum,count);
                if(arr[i] == 0) count--;
                i++;
            }
            j++;
        }
        
        return minimum == INT_MAX ? -1 : minimum;
    }
};