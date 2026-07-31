#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node(int val){
        data=val;
        next=nullptr;
    }
};

//Insert At Biginning
void insertathead(node *&head,int val){
    node *n1=new node(val);//constractor call
    n1->next=head; 
    head=n1;
}
//Reverse The Singly LinkedList
node *reverse(node *head){
    node *cur=head;//cur points to head
    node *prev=nullptr;//prev points to NULL
while(cur){
   node *after=cur->next;//'after' points to the node that originally comes after 'cur'.
    cur->next=prev;//cur's next pointer points to prev node
    prev=cur;//prev node moves forward
    cur=after;//cur node moves forward
}
return prev;//return the prev node
}

//Print SLL
void printLL(node *head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"nullptr"<<endl;
}

int main() 
{
node *head=nullptr;
insertathead(head,50);
insertathead(head,40);
insertathead(head,30);
insertathead(head,20);
cout<<"The Singly Linked List is: ";
printLL(head);
cout<<"The Singly Linked List in Reverse: ";
head=reverse(head);
printLL(head);
    return 0;
}