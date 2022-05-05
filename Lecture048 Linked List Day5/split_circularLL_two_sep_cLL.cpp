#include<iostream>
#include<map>
using namespace std;


class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this-> next = NULL;
    }
};

// int len(Node* &head){
//     Node* cur = head;
//     int count=0;
//     while(cur!=NULL){
//         count++;
//         cur=cur->next;
//     }
//     return(count);
// }

//Inserting the elements to the linked list.

void insertatend(Node* &head,Node* &tail, int data)
{
    Node* temp = new Node(data);
    if(head == NULL && tail == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail=temp;
    }
}

//Making the LL circular:

void make_circular(Node* &head,Node* &tail){
    tail->next = head;
}

//splitting cicular in two equal half singly linked list.

void remove_circular(Node* &head, Node* &tail,Node* &first, Node* &second)
{
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=head)
    {
        fast = fast->next;
        if(fast!=head){
            fast = fast->next;
        }
        else
        {
            break;
        }
        if (fast->next->next == head)
        {
            break;
        }
        slow = slow->next;
    }
    first = head;
    second = slow->next;
    tail->next = second;
    slow->next = head;
    
}


void print(Node* &head){
    int count=0;
    Node* cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" -> ";
        cur=cur->next;
        count++;
    }
    cout<<endl;
    cout<<"Final Length of the  linked list is: "<<count<<endl;
}

//To print the circular LL
void print_circular(Node* N){
    int count=0;
    Node* cur = N;
    while(count!=30)
    {
        cout<<cur->data<<" -> ";
        cur=cur->next;
        count++;
    }
    cout<<endl;
    cout<<"Final Length of the  linked list is: "<<count<<endl;
}


int main(){
    Node * head = NULL;
    Node * tail = NULL;
    Node * first = NULL;
    Node * second = NULL;
    cout<<endl;
    insertatend(head,tail,1);
    insertatend(head,tail,2);
    insertatend(head,tail,3);
    insertatend(head,tail,4);
    insertatend(head,tail,5);
    insertatend(head,tail,6);
    insertatend(head,tail,7);
    insertatend(head,tail,8);
    insertatend(head,tail,9);
    insertatend(head,tail,10);
    insertatend(head,tail,11);
    insertatend(head,tail,12);
    cout<<"Linked List: ";
    print(head);
    cout<<endl;
    cout<<"Circular Linked List: ";
    make_circular(head,tail);
    print_circular(head);
    remove_circular(head,tail,first,second);
    cout<<endl;
    cout<<"First Linked List is: ";
    print_circular(first);
    cout<<endl;
    cout<<"second Linked List is: ";
    print_circular(second);
    cout<<endl;

}