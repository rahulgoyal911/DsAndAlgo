using namespace std;
#include<iostream>
struct Node{
    int data;
    struct Node *left,*right;
};
struct Node *newNode(int item) { 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
struct Node* insert(struct Node* node, int data) { 
    if (node == NULL) return newNode(data); 
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    
    return node; 
} 
int isBst(Node *root){
    if(root == NULL)
    return 1;

    if(root->left !=NULL && root->left->data > root->data)
    return 0;

    if(root->right !=NULL && root->right->data < root->data)
    return 0;

    if(!isBst(root->left) || !isBst(root->right))
    return 0;

    return 1;

}
void printInOrder(Node *head){
    if(head == NULL)
        return;
    printInOrder(head->left);
    cout<<head->data<<" ";
    printInOrder(head->right);   
}
struct Node *minValueNode(struct Node* root){
    struct Node* current = root; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 

}
struct Node* deleteNode(Node *root,int data){
    if(root == NULL)
    return root;

    if(data < root->data)
    root->left = deleteNode(root->left,data);

    else if(data > root->data)
    root->right = deleteNode(root->right,data);

    else{
        if(root->left == NULL){
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        }
        else if(root->right == NULL){
            struct Node *temp = root->left; 
            free(root); 
            return temp; 
        }
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}
int isPresent(Node *root,int data){
    if(root == NULL)
    return 0;
    if(root->data == data)
    return 1;
    int l = isPresent(root->left,data);
    int r = isPresent(root->right,data);

    if(l || r )
    return 1;
    else
    {
        return 0;
    }
    
}

int main(){
    struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // // print inoder traversal of the BST 
    // printInOrder(root);
    // cout<<endl;
    // cout<<"isBst: "<<isBst(root)<<endl;
    // deleteNode(root,60);
    // printInOrder(root);
    // cout<<endl;
    cout<<"Is PResent: "<<isPresent(root,90);
   
    return 0;    

}