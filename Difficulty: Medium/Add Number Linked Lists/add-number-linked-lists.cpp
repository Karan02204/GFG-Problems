/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* List){
        Node* prev = NULL;
        Node* curr = List;
        while(curr!=NULL){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            
        }
        
        return prev;
        
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node* temp1 = reverseList(num1);
        Node* temp2 = reverseList(num2);
        Node* dummy = new Node(0);
        Node* temp = dummy;
        
        int carry = 0;
        while(temp1!=NULL || temp2!=NULL || carry){
            int sum = 0;
            
            if(temp1!=NULL){
                sum = sum + temp1->data;
                temp1 = temp1->next;
            }
            
            if(temp2!=NULL){
                sum += temp2->data;
                temp2 = temp2->next;
            }
            
            sum = sum +carry;
            Node* newHead = new Node(sum%10);
            carry = sum/10;
            
            temp->next = newHead;
            temp = temp->next;
        }
        
        dummy = reverseList(dummy->next);
        while(dummy->data == 0){
            dummy = dummy->next;
        }
        return dummy;
        
    }
};