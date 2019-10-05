using namespace std;
#include<iostream>
struct node{
    int data;
    struct node *next;
}*start,*ptr,*result,*head;

void reverse(node *current) { 
        // Initialize current, previous and 
        // next pointers 
        struct node *prev = NULL, *next = NULL;
        head = NULL; 

        while (current != NULL) 
        { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's p, *next = NULLpointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
}
void printInReverse(node *ptr){
    if(ptr==NULL)
    {
        return;
    }
    printInReverse(ptr->next);
    cout<<ptr->data<<" , ";
}

void printLinked(node *ptr){
    while(ptr != NULL) {
        
        cout<<ptr->data<<" , ";
        ptr = ptr->next;           
    
    }
}
void insertValues(node *ptr){
     for(int i=1;i<5;i++){
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=(i)*10;
        ptr->next=NULL;
        start->next = ptr;
        start = start->next;
    }
}
node* insertStart(node *ptr,int value){
    struct node *ins = NULL;
    ins = (struct node*)malloc(sizeof(struct node));
    ins->data = value;
    ins->next = ptr;
    return ins;
}
void insertEnd(node *ptr,int value){
    while(ptr->next !=  NULL){
        ptr = ptr->next;
    }
    struct node *ins = NULL;
    ins = (struct node*)malloc(sizeof(struct node));
    ins->data = value;
    ins->next = NULL;
    ptr->next = ins;
}

void insertBetween(node *ptr,int value,int posotion){
    for(int i=0;i<posotion;i++){
        ptr = ptr->next;
    }
    struct node *ins = NULL;
    ins = (struct node*)malloc(sizeof(struct node));
    ins->data = value;
    ins->next = ptr->next;
    ptr->next = ins;
}

node* deleteFirst(node *ptr){
    return ptr->next;
}

void  deleteLast(node *ptr){
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;
}
void deleteAny(node *ptr,int pos){
    for(int i=0;i<pos-1;i++){
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;

}
int main()
{
    start = (struct node*)malloc(sizeof(struct node));
    //initialising
    start->data=NULL;
    start->next=NULL;
    
    ptr=start;
    result=start;

    //inserting data into linkedlist
    insertValues(ptr);
    ptr=result;
    //printing linkedlist
    cout<<"After inserting data in linkedlist"<<endl;
    printLinked(ptr);
    cout<<endl;

    //print linkedlist in reverse order
    cout<<"Printing list in reverse order by recursion"<<endl;
    ptr=result;
    printInReverse(ptr);
    cout<<endl;

    //reversing a linkedlist
    
    ptr=result;
    reverse(ptr);

    //printing final reversed linkedlist
    cout<<"After Reversing list"<<endl;
    ptr=head;
    printLinked(ptr);
    cout<<endl;

    // insert a node at begining 
    cout<<"After inserting at begining"<<endl;
    head = insertStart(ptr,33);
    ptr = head;
    printLinked(ptr);
    cout<<endl;

    // insert a node at end of linkedlist
    cout<<"After inserting at end"<<endl;
    insertEnd(ptr,66);
    ptr = head;
    printLinked(ptr);
    cout<<endl;

    // insert a node in anywhere
    cout<<"After inserting at position"<<endl;
    insertBetween(ptr,99,3);
    ptr = head;
    printLinked(ptr);
    cout<<endl;

    // delete first node
    cout<<"After Deleting first node"<<endl;
    head = deleteFirst(ptr);
    ptr = head;
    printLinked(ptr);
    cout<<endl;

    // delete last node
    cout<<"After Deleting last node"<<endl;
    deleteLast(ptr);
    ptr = head;
    printLinked(ptr);
    cout<<endl;

    // delete any node
    cout<<"After Deleting any node"<<endl;
    deleteAny(ptr,3);
    ptr = head;
    printLinked(ptr);
    cout<<endl;


    return 0;
}