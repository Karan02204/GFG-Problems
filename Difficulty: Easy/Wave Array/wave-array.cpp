class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size()-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
    }
};