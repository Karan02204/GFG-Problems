class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int i=0 , j=0 , k=0;
        int minLength = INT_MAX;
        string result;
        int n = s1.size();
        int m = s2.size();
        
        while(j<n){
            if(s1[j] == s2[k]){
                k++;
            }
            
            if(k == s2.size()){
                i=j;
                k =s2.size() - 1;
                
                while(i>=0 && k>=0){
                    if(s1[i] == s2[k]){
                        k--;
                    }
                    i--;
                }
                i++;
                if(j-i+1 < minLength){
                    minLength = j-i+1;
                    result = s1.substr(i , minLength);
                }
                k=0;
                j=i+1;
            }
            
            j++;
        }
        
        return result;
    }
};
