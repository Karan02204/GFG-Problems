class Solution {
  public:
    void func(vector<int>& arr,vector<int>& result,int index, int currsum){
        if(index == arr.size()){
            result.push_back(currsum);
            return;
        }
        
        //include.
        func(arr,result,index+1,currsum+arr[index]);
        
        //exclude.
        func(arr,result,index+1,currsum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> result;
        func(arr,result,0,0);
        return result;
    }
};