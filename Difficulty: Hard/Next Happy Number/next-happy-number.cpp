class Solution {
  public:
    int digitSum(int n){
        if(n == 0) return 0;
        int d = n%10;
        return d*d + digitSum(n/10);
    }
    
    bool isHappy(int n){
        if(n == 1) return true;
        if(n == 4) return false;
        
        return isHappy(digitSum(n));
    }
    
    int nextHappy(int N) {
        // code here
        N++;
        if(isHappy(N)) return N;
        return nextHappy(N);
    }
};