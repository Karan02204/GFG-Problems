class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int currsum = 0 , i=0 , j=0;
        vector<int> result;
        
        while(j<arr.size()){
            currsum += arr[j];
            
            while(currsum > target){
                currsum -= arr[i];
                i++;
            }
            
            if(currsum == target){
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }
            
            j++;
        }
        
        if(result.size() == 0){
            result.push_back(-1);
        }
        
        return result;
    }
};