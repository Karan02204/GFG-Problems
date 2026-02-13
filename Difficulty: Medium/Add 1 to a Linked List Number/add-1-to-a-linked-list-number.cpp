/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head){
        Node* curr = head , *prev = NULL;
        
        while(curr!=NULL){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        
        // return head of list after adding one
        head = reverseList(head);
        Node* curr = head;
        int carry = 1;
        while(curr && carry){
            int sum = curr->data + carry;
            curr->data = sum%10;
            carry = sum/10;
            
            if(!curr->next && carry){
                Node* node = new Node(carry);
                curr->next = node;
                carry =0;
            }
            curr = curr->next;
        }
        
        head = reverseList(head);
        return head;
    }
};