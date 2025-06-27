class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        // code here
        for(int i=0;i<arr.size();i+=k){
            int low = i;
            int high = min(i+k-1,(int)arr.size()-1);
            while(low < high){
                swap(arr[low],arr[high]);
                low++;
                high--;
            }
        }
        
    }
};
