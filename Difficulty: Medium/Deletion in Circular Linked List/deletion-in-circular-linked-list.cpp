/*
class Node {
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
    Node* deleteNode(Node* head, int key) {
        
        if(head == NULL) return NULL;
        // code here
        Node* curr = head;
        Node* temp = head;
        // delete node at head
        if(head->data == key && head->next == head){
            delete head;
            return NULL;
        }
        if(head->data == key){
            while(curr->next!=head){
                curr = curr->next;
            }
            head = head->next;
            curr->next = head;
            delete temp;
            return head;
        }
        
        while(curr->next!=head){ // delete in middle
            if(curr->next->data == key){
                Node* nextNode = curr->next;
                curr->next = nextNode->next;
                delete nextNode;
                return head;
            }
            curr = curr->next;
        }
        
        return head;
        
    }
};