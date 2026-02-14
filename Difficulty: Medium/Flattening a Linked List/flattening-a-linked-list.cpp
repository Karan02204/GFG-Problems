/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeTwoSortedLinkedList(Node* left , Node* right){
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while(left!=NULL && right!=NULL){
            if(left->data <= right->data){
                temp->bottom = left;
                left = left->bottom;
            } else{
                temp->bottom = right;
                right = right->bottom;
            }

            temp = temp->bottom;
        }

        if(left!=NULL){
            temp->bottom = left;
        } else{
            temp->bottom = right;
        }

        return dummy->bottom;
    }
    
    Node* findMiddle(Node* head){
        if (head == nullptr || head->bottom == nullptr) {
            return head;
        }

        Node* slow = head , *fast = head->next;
        while(fast!=NULL && fast->bottom!=NULL){
            slow = slow->next;
            fast = fast->bottom->bottom;
        }

        return slow;
    }

    Node* sortList(Node* head) {
        if(head == NULL || head->bottom == NULL) return head;
        
        Node* middle = findMiddle(head);
        Node* right = middle->bottom;
        middle->bottom = NULL;
        Node* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedLinkedList(left , right);
    }
    
    Node *flatten(Node *root) {
        // code here
        Node* temp = root;
        while(temp!=NULL){
            if(temp->bottom!=NULL){
                Node* nextNode = temp->next;
                temp->next = NULL;
                Node* child = temp->bottom;
                while(child->bottom!=NULL){
                    child = child->bottom;
                }
                child->bottom = nextNode;
            } else{
                temp->bottom = temp->next;
                temp->next = NULL;
            }
            temp = temp->bottom;
        }
        
        return sortList(root);
        
    }
};