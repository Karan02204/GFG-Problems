class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        map<int,int> m;
        m[0] = 1;
        int sum = 0;
        int count = 0;
        
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            
            if(m.find(sum)!=m.end()){
                count+=m[sum];
            }
            
            m[sum]++;
        }
        
        return count++;
    }
};