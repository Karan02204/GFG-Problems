/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newNode = new Node(data);
        Node* curr = head;
        
        if(data <= head->data){ //add at the head
            while(curr->next!=head){
                curr = curr->next;
            }
            
            newNode->next = head;
            head = newNode;
            curr->next = head;
            return head;
        }
        
        while(curr->next!=head){ // add in the middle
            if(curr->next->data > data){
                newNode->next = curr->next;
                curr->next = newNode;
                return head;
            } else{
                curr = curr->next;
            }
        }
        
        newNode->next = head;
        curr->next = newNode;
        return head;
        
    }
};