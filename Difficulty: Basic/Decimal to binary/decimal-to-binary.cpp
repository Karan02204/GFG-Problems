class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string answer = "";
        while(n>0){
            int remainder = n%2;
            n=n/2;
            answer+=to_string(remainder);
        }
        
        reverse(answer.begin(),answer.end());
        return answer;
    }
};