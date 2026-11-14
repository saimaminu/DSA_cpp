#include <iostream>
using namespace std;

/*BST--->Binary Search Tree
Understanding how the recursive calls return updated pointers
 is particularly important for mastering BSTs*/

//Node creation with two pointers and a value
struct node{
    int data;
    node *left;
    node *right;
    node(int val){ //Constructor define and Initialize
        data=val;
        right=left=nullptr;
    }

};
//Insertion
node *BST_insert(node *root,int val){
        if(!root){node *n1=new node(val);
         return n1;
        }
        else if(val>root->data) root->right=BST_insert(root->right,val);
        else if(val<root->data) root->left=BST_insert(root->left,val);
        else cout<<"Duplicate Value"<<endl;
        return root;
}
//InorderSuccessor to find last left node of a tree/subtree 
node* inordersuccessor(node *root){
    while(root->left) root=root->left;
    return root;
}
//Deletion
node *delete_BST(node *root,int val){
    if(!root){
        cout<<"nullptr"<<endl;
        return root;
    }
    else if(val>root->data) root->right=delete_BST(root->right,val);
    else if(val<root->data) root->left=delete_BST(root->left,val);

    //If val is found
    else{
        //No Child
        if(!root->left and !root->right){
            delete root;
            return nullptr;
        }
        //One Child at left
        else if(root->left){
            node* tmp=root->left;
            delete root;
            return tmp;
        }
        //One Child at right
        else if(root->right){
            node* tmp=root->right;
            delete root;
            return tmp;
        }
        //two Child
        else{
            node* tmp=inordersuccessor(root->right);
            root->data=tmp->data;
            root->right=delete_BST(root->right,tmp->data);
        }
    }
    return root;
}

//Search a perticular node
void search(node *root, int val){
if(!root){
    cout<<"Not Found"<<endl;
    return;
}
if(val==root->data) cout<<"Found"<<endl;
else if(val>root->data) search(root->right,val);    
else if(val<root->data) search(root->left,val);
}

//inorder traversal
void inorder(node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//preorder traversal
void preorder(node *root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//postorder traversal
void postorder(node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root=nullptr;
    root= BST_insert(root,10);
    root= BST_insert(root,20);
    root= BST_insert(root,5);
    root= BST_insert(root,40);
    root= BST_insert(root,50);
    root= BST_insert(root,6);
    root= BST_insert(root,70);
    search(root,100);
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl<<"Preorder: ";
    preorder(root);
    root=delete_BST(root,20);
    cout<<endl<<"Postorder: ";
    postorder(root);
    return 0;
}