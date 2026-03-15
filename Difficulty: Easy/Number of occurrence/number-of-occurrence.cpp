class Solution {
  public:
    int helper_first(vector<int>& arr , int target){
        int ans = -1;
        
        int low = 0;
        int high = arr.size() -1 ;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(arr[mid] == target){
                ans = mid;
                high = mid - 1;
            } else if(arr[mid] > target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    int helper_last(vector<int>& arr , int target){
        int ans = -1;
        
        int low = 0;
        int high = arr.size() -1 ;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(arr[mid] == target){
                ans = mid;
                low = mid + 1;
            } else if(arr[mid] > target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = helper_first(arr,target);
        if(first == -1) return 0;
        
        int last = helper_last(arr , target);
        return last - first + 1;
    }
};
