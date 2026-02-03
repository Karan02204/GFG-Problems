class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int i=0,j=0;
        int size = s.size();
        int maxi = -1;
        unordered_map<char,int> mp;
        while(j<size){
            mp[s[j]]++;
            
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            
            if(mp.size() == k){
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        
        return maxi;
    }
};