class Solution {
  public:
    int countOccur(vector<int>& arr , int low , int high , int target){
        if (low > high) return 0;
        
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return 1+ countOccur(arr,low,mid-1,target) + countOccur(arr,mid+1,high,target);
        } else if(arr[mid] > target){
            countOccur(arr,low,mid-1,target);
        } else{
            countOccur(arr,mid+1,high,target);
        }
        
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int low = 0;
        int high = arr.size()-1;
        
        return countOccur(arr, low , high , target);
    }
};
