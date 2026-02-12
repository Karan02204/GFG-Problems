/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zerodummy = new Node(-1);
        Node* onedummy = new Node(-1);
        Node* twodummy = new Node(-1);
        
        Node* zerotail = zerodummy;
        Node* onetail = onedummy;
        Node* twotail = twodummy;
        
        Node* curr = head;
        
        while(curr!=NULL){
            if(curr->data == 0){
                zerotail->next = curr;
                zerotail = zerotail->next;
            } else if(curr->data == 1){
                onetail->next = curr;
                onetail = onetail->next;
            } else {
                twotail->next = curr;
                twotail = twotail->next;
            }
            curr = curr->next;
        }
        
        zerotail->next = onedummy->next ? onedummy->next : twodummy->next;
        onetail->next = twodummy->next;
        twotail->next = NULL;
        
        return zerodummy->next;
    }
};