#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtHead(Node* &head, int val){
    Node* n = new Node(val); // created new node dynamically
    // if linked list is empty
    if(head == NULL){
        n -> next = n; // saving its own address 
        head = n; // alloting it as head
        return;

    }

    Node* temp = head; //created temperory pointer so that address of head is not lost
    // traversing to last node
     while(temp -> next != head){
        temp = temp -> next;
    }

    temp -> next = n;
    n -> next = head;
    head = n; // reassigned new node as head

}
void insertAtTail(Node* &head, int val){
    //if linked list is empty
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;
    // traversing to last node 
    while(temp -> next != head){
        temp = temp -> next;
    }

    temp -> next = n;
    n -> next = head; // linked last element to head to make it circular
}

void display(Node* head){
    Node* temp = head;
    cout << temp -> data <<" ";
    while(temp -> next != head){
        temp = temp-> next;
        cout << temp -> data <<" ";

    }
    cout<< endl;
}
void deleteAtHead(Node* &head){
    Node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;

    }
    Node* todelete = head; //created pointer to delete dynamic node
    temp -> next = head -> next;
    head = head -> next;

    delete todelete;

}
void deleteion(Node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count != pos - 1){
        temp = temp -> next;
        count++;
    }
    Node* todelete = temp -> next;
    temp->next = temp-> next-> next;

    delete todelete;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 24);
    insertAtTail(head, 35);
    insertAtTail(head, 46);
    display(head);
    insertAtHead(head, 52);
    display(head);
    deleteion(head, 5);
    display(head);
    deleteion(head, 1);
    display(head);
}

// Q1. While traversing a single-circular linked list, 
// which condition establishes that the traversing element/variable has reached the first element?
// Ans 1:- when we create a new linked list we set first element as head and when we continue to add elements to linked list
// we add address of first element(head) in the last element(tail) so that it makes the list circular.
// while traversing the linked list we create a temp pointer which points to head so that while traversing orignal head 
// address is not lost. when we arrive at the tail of linked list 
//            temp -> next = head will point to head
// and        temp = temp -> next   
// temp will now be our head 
// or
// while traversing we can simply put a condition 
// do{
//     temp = temp -> next;
// }
// while(temp != head);
//this will stop when temp is head

// Q2. What are the practical applications of a circular linked list?
// ANS 2. 1)In multiplayer games where players are placed in circular linked list and then their turns come one by one
//        2)swithcing tabs in microsoft edge ctrl + Tab
//        3) To loop songs in playlist.
