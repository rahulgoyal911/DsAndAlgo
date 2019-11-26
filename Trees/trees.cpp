using namespace std;
#include<iostream>
#include<map>
#include<queue>
#include<vector>


struct Node{
    int data;
    struct Node *left,*right;
};
void printPreOrder(Node *head){
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    printPreOrder(head->left);
    printPreOrder(head->right);  
}
void printInOrder(Node *head){
    if(head == NULL)
        return;
    printInOrder(head->left);
    cout<<head->data<<" ";
    printInOrder(head->right);   
}
void printPostOrder(Node *head){
    if(head == NULL)
        return;
    printPostOrder(head->left);
    printPostOrder(head->right);
    cout<<head->data<<" ";
}
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int getHeight(Node *head){
    if(head == NULL)
        return 0;
    else{
        int ldepth = getHeight(head->left);
        int rdepth = getHeight(head->right);

        if(ldepth>rdepth){
            return ldepth + 1;
        }
        else
        {
            return rdepth + 1;
        }
        
    }
}
bool printAncestors(Node *root,int target){
    if(root == NULL)
        return false;
    if(root->data == target)
        return true;
    if(printAncestors(root->left,target) || printAncestors(root->right,target)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
void printGivenLevel(Node *root,int level,bool ltr){
    if(root == NULL)
    return;
    if(level == 1){
        cout<<root->data<<" ";
    }
    else if(level > 1)
    {
        if(ltr){
            printGivenLevel(root->left,level-1,ltr);
            printGivenLevel(root->right,level-1,ltr);
        }
        else{
            printGivenLevel(root->right,level-1,ltr);
            printGivenLevel(root->left,level-1,ltr);
        }
        
    }
}
void printLevelOrder(Node *root){
    int h = getHeight(root);
    bool ltr=  true;
    for(int i=1;i<=h;i++){
        printGivenLevel(root,i,ltr);
    }
}
void printReverseLevelOrder(Node *root){
    int h = getHeight(root);
    bool ltr = true;
    for(int i=h;i>=1;i--){
        printGivenLevel(root,i,ltr);
    }
}
void printSpiralLevelOrder(Node *root){
    int h = getHeight(root);
    bool ltr = true;
    for(int i=1 ; i<=h;i++){
        printGivenLevel(root,i,ltr);
        ltr = !ltr;
    }

}
void mirrorTree(Node *root){
    if(root == NULL)
    return;
    else{
        mirrorTree(root->left);
        mirrorTree(root->right);
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
}
void getVerticalOrder(Node *root,int hd,map<int,vector<int>> &m){
    if(root == NULL)
    return;

    m[hd].push_back(root->data);
    getVerticalOrder(root->left,hd-1,m);
    getVerticalOrder(root->right,hd+1,m);
}
void printVerticalOrder(Node *root){
    map <int,vector<int>> m;
    int hd = 0;
    getVerticalOrder(root,hd,m);

    map<int,vector<int>> :: iterator it;
    for(it = m.begin(); it!=m.end() ; it++){
        for(int i = 0;i<it->second.size();++i){
            cout<<it->second[i]<<" ";
        }cout<<endl;
    }
}
int max(int a,int b){
    if(a>b)
    return a;
    else
    {
        return b;
    }
    
}
int getDiameter(Node *root){
    if(root == NULL)
    return 0;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);

    int lDiameter = getDiameter(root->left);
    int rDiameter = getDiameter(root->right);

    return max(lHeight+rHeight+1 , max(lDiameter,rDiameter));
    
}
void deleteTree(Node *root){
    if(root ==NULL)
    return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
struct Node* findLCA(Node* root,int n1,int n2){
    if( root == NULL)
    return NULL;

    if(root->data == n1 || root->data == n2)
    return root;

    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 

    if(left_lca && right_lca)
    return root;

    if(left_lca != NULL){
        return left_lca;
    }
    else if(right_lca !=NULL)
    {
        return right_lca;
    }
    // return (left_lca != NULL)? left_lca: right_lca;
}
void fillmapTopView(Node *root,int d,int l,map<int,pair<int,int>> &m){
    if(root ==NULL)
    return;
    if(m.count(d) == 0){
        m[d] = make_pair(root->data,l);
    }
    else if(m[d].second > l){
        m[d] = make_pair(root->data,l);
    }
    fillmapTopView(root->left,d-1,l+1,m); 
    fillmapTopView(root->right,d+1,l+1,m);
}
void printTopView(Node *root){
    map<int,pair<int,int>> m;
    fillmapTopView(root,0,0,m);

    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->second.first<<" ";
    }
}
void fillmapBottomView(Node *root,int d,int l,map<int,pair<int,int>> &m){
    if(root ==NULL)
    return;
    if(m.count(d) == 0){
        m[d] = make_pair(root->data,l);
    }
    else if(m[d].second <= l){
        m[d] = make_pair(root->data,l);
    }
    fillmapBottomView(root->left,d-1,l+1,m); 
    fillmapBottomView(root->right,d+1,l+1,m);
}
void printBottomView(Node *root){
    map<int,pair<int,int>> m;
    fillmapBottomView(root,0,0,m);

    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->second.first<<" ";
    }
}

int main(){
    struct Node *root  = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(10);
    root->right->right->right = newNode(11);
    printBottomView(root);
    // cout<<"Preorder: ";
    // printPreOrder(root);
    // cout<<"\n";
    // cout<<"INorder: ";
    // printInOrder(root);
    // cout<<"\n";
    // cout<<"POSTorder: ";
    // printPostOrder(root);
    // cout<<"\n";
    // cout<<"height: "<<getHeight(root)<<"\n";
    // cout<<"Ancesstors: ";
    // printAncestors(root,7);
    // cout<<"\n";
    // cout<<"Level Order: ";
    // printLevelOrder(root);
    // cout<<"\n";
    // cout<<"Reverse Level Order: ";
    // printReverseLevelOrder(root);
    // cout<<"\n";
    // cout<<"Spiral Level Order: ";
    // printSpiralLevelOrder(root);
    // cout<<"\n";
    // //  cout<<"Mirror Tree: ";
    // //  mirrorTree(root);
    // //  printLevelOrder(root);
    // //  cout<<"\n";

    // cout<<"Vertical order: "<<endl;
    // printVerticalOrder(root);

    // cout<<"Diameter: "<<getDiameter(root)<<endl;

    // // cout<<"delete tree: "<<endl;
    // // deleteTree(root);

    // cout<<findLCA(root,4,5)->data;

    
    return 0;
}

