/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow = head , *fast = head;
        Node* temp =head;
        int length = 1;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                slow = slow->next;
                
                while(slow!=fast){
                    slow = slow->next;
                    length++;
                }
                return length;
                
            }
        }
        
        return 0;
    }
};