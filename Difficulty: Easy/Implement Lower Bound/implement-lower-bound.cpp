class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int low = 0 , high = arr.size() - 1;
        int answer = -1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(arr[mid] >= target){
                answer = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        
        return (answer == -1) ? arr.size() : answer;
    }
};
