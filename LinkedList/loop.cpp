using namespace std;
#include<iostream>
struct Node { 
    int data; 
    struct Node* next; 
};
void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node(); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
void removeLoop(struct  Node* loop_node,struct Node *head){
    struct Node *ptr1;
    struct Node *ptr2;

    ptr1 = head;
    while(1){
        ptr2 = loop_node;
        while(ptr2->next != loop_node && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        if(ptr2->next == ptr1)
            break;
        ptr1 =  ptr1->next;

    }
    ptr2->next = NULL;
}
int detectAndRemoveLoop(struct Node *head){
    struct Node * slp = head,*fsp = head;
    while(slp && fsp && fsp->next){
        slp = slp->next;
        fsp = fsp->next->next;

        if(slp == fsp){
            removeLoop(slp,head);
            return 1;
        }
    }
}
int main() 
{ 
    struct Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 

    head->next->next->next->next->next = head->next->next; 
    // printList(head); 
    detectAndRemoveLoop(head); 
  
    cout << "Linked List after removing loop" << endl; 
  
    printList(head); 
  
    return 0; 
} 